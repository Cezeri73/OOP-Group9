#include "Room.h"

// Static vector to hold all room instances
std::vector<Room *> Room::allRooms;

// Constructor for Room, initializes with a name and adds to the list of all rooms
Room::Room(std::string &name) : roomName(name)
{
    allRooms.push_back(this); // Adds the current room to the global list of rooms
}

// Method to display the room interface
void Room::showRoom()
{
    std::string name = roomName;
    
    // Create a window to display room details
    Fl_Window *roomWindow = new Fl_Window(400, 400, name.c_str());
    
    // Create buttons for different actions in the room
    Fl_Button *removeDeviceButton = new Fl_Button(100, 60, 200, 30, "Remove Device");
    Fl_Button *addTimerButton = new Fl_Button(100, 100, 200, 30, "Add Timer");

    // Button to add a new device to the room
    Fl_Button *addDeviceButton = new Fl_Button(100, 20, 200, 30, "Add Device");
    // Set callback for adding device to the room
    addDeviceButton->callback([](Fl_Widget *widget, void *data)
                              {
        Fl_Window *parent_window = widget->window(); // Hide the current window
        parent_window->hide();

        Room *r = static_cast<Room*>(data);
        r->ads.show(); // Show the add device screen
        while (r->ads.shown()) {
            Fl::wait(); // Wait for the add device window to be closed
        }
        r->addDevice(r->ads.choice->value()); // Add the selected device
        r->showRoom(); // Re-show the room interface
    },
                              this);

    // Set callback for the "Remove Device" button
    removeDeviceButton->callback([](Fl_Widget *widget, void *data)
                                 {
        Fl_Window *parent_window = widget->window();
        parent_window->hide();

        Room *r = static_cast<Room*>(data);
        r->rds.show(); // Show the remove device screen
        while (r->rds.shown()) {
            Fl::wait(); // Wait for the remove device window to be closed
        }
        r->removeDevice(r->rds.choice->value()); // Remove the selected device
        r->showRoom(); // Re-show the room interface
    }, this);

    // Set callback for the "Add Timer" button
    addTimerButton->callback([](Fl_Widget *widget, void *data)
                             {
            Fl_Window *parent_window = widget->window();
            parent_window->hide();

            Room *r = static_cast<Room *>(data);

            // Create a window for adding a timer
            Fl_Window *window = new Fl_Window(300, 200, "Add Timer Screen");

            // Dropdown choice for selecting a device
            Fl_Choice *choice = new Fl_Choice(100, 50, 100, 30, "Device:");
            if (!r->devices.empty())
            {
                for (const auto &device : r->devices)
                {
                    choice->add(device->getName()); // Add device names to the choice menu
                }
            }

            // Input for entering the timer duration
            Fl_Input *timeInput = new Fl_Input(100, 90, 100, 30, "Hour:");
            Fl_Button *button = new Fl_Button(110, 130, 80, 30, "Enter");

            // Callback to handle timer logic
            button->callback([](Fl_Widget *widget, void *data)
                             {
            auto *callbackData = static_cast<std::pair<Room *, Fl_Choice *> *>(data);
            Room *room = callbackData->first;
            Fl_Choice *deviceChoice = callbackData->second;

            // Retrieve timer duration from input
            Fl_Input *timeInput = static_cast<Fl_Input *>(widget->parent()->child(1));
            const char *timeStr = timeInput->value();
            int seconds = std::atoi(timeStr); // Convert input to seconds

            if (deviceChoice->value() >= 0 && seconds > 0)
            {
                SmartDevice *selectedDevice = room->devices.at(deviceChoice->value());

                // Callback for when the timer ends
                auto timeoutCallback = [](void *data)
                {
                    SmartDevice *device = static_cast<SmartDevice *>(data);

                    // Simulate triggering the device's callback
                    Fl_Button tempButton(0, 0, 0, 0, "Temp");
                    Fl_Window tempWindow(0, 0, 100, 100, "Temp Window");
                    tempButton.parent(&tempWindow);
                    device->deviceCallback(&tempButton, device);
                    device->addNotification("Device turned on after timer!");
                };

                // Handle thermostat devices differently
                if (selectedDevice->type == SmartDevice::Type::Thermostat)
                {
                    Fl_Button *tempButton = new Fl_Button(0, 0, 0, 0, "Temp");
                    selectedDevice->hour = seconds;
                    selectedDevice->deviceCallback(tempButton, selectedDevice);
                }
                else
                {
                    Fl::add_timeout(seconds, timeoutCallback, selectedDevice); // Add timeout callback
                }
            }

            widget->window()->hide(); // Close the timer window
        },
                             new std::pair<Room *, Fl_Choice *>(r, choice));

            window->end();
            window->show();

            // Wait until the timer window is closed
            while (window->visible())
            {
                Fl::wait(); // Wait for user interaction
            }

            r->showRoom(); // Re-show the room interface
        },
                             this);

    // Add buttons for each device in the room
    int yPosition = 100;
    for (size_t i = 0; i < devices.size(); ++i)
    {
        Fl_Button *deviceButton = new Fl_Button(100, yPosition, 200, 30, devices[i]->getName());
        deviceButton->callback([](Fl_Widget *widget, void *data)
                               {
            SmartDevice *dev = static_cast<SmartDevice *>(data);
            dev->deviceCallback(widget, data); // Trigger the device's callback
        },
                               devices[i]);
        yPosition += 40; // Adjust button's vertical position for each device
    }

    roomWindow->end();
    roomWindow->show(); // Show the room window with all devices
}

// Adds a new device to the room based on user selection
void Room::addDevice(int selection)
{
    SmartDevice *device;

    // Create devices based on the user's selection
    switch (selection)
    {
    case 2:
        device = new Light("Light");
        break;
    case 1:
        device = new Thermostat("Thermostat", 22);
        break;
    case 0:
        device = new Refrigerator("Refrigerator");
        break;
    case 3:
        device = new WaterPurifier("Water Purifier");
        break;
    case 4:
        device = new Elevator("Elevator");
        break;
    case 6:
        device = new SecurityCamera("Camera");
        break;
    case 5:
        device = new Curtain("Curtain");
        break;
    case -1:
        return; // If no valid selection, do nothing
    }

    devices.push_back(device); // Add the new device to the room
}

// Removes a device from the room by its type
void Room::removeDevice(int type)
{
    // Iterate through devices in reverse order to avoid invalidating the vector during removal
    for (int i = devices.size() - 1; i >= 0; --i)
    {
        if (static_cast<int>(devices[i]->type) == type)
        {
            devices.erase(devices.begin() + i); // Remove the device from the room
            break; // Exit after removing the first matching device
        }
    }
}

// Adds a device directly to the room (used by JSON deserialization)
void Room::addDevice(SmartDevice *device)
{
    devices.push_back(device); // Add the device to the room
}

// Equality operator to compare rooms by name
bool Room::operator==(Room &otherRoom)
{
    return roomName == otherRoom.roomName; // Compare rooms based on their names
}

// Serializes the room data to JSON format
json Room::toJson() const
{
    json deviceArray = json::array();
    for (const auto &device : devices)
    {
        deviceArray.push_back(device->toJson()); // Serialize each device
    }
    return json{{"roomName", roomName}, {"devices", deviceArray}}; // Return room and devices as JSON
}

// Deserializes room data from JSON format
void Room::fromJson(const json &j)
{
    std::string roomName = j.at("roomName").get<std::string>();
    Room *room = new Room(roomName); // Create a new room from the JSON data
    for (const auto &deviceJson : j.at("devices"))
    {
        int typeInt = deviceJson.at("type").get<int>(); // Get device type from JSON
        room->addDevice(typeInt); // Add the corresponding device to the room
    }
}
