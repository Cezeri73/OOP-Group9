#include "Room.h"

// Static vector to hold all room instances
std::vector<Room *> Room::allRooms;

// Constructor for Room, initializes with a name and adds to the list of all rooms
Room::Room(std::string &name) : roomName(name)
{
    allRooms.push_back(this);
}

// Method to display the room interface
void Room::showRoom()
{
    // Create a window for the room
    std::string name = roomName;
    Fl_Window *roomWindow = new Fl_Window(400, 400, name.c_str());

    // Button to add a new device to the room
    Fl_Button *addDeviceButton = new Fl_Button(100, 20, 200, 30, "Add Device");
    addDeviceButton->callback([](Fl_Widget *widget, void *data)
                              {
        Fl_Window *parent_window = widget->window(); // Hide the current window
        parent_window->hide();

        Room *r = static_cast<Room*>(data);
        r->ads.show(); // Show the add device screen
        while (r->ads.shown()) {
            Fl::wait();
        }
        r->addDevice(r->ads.choice->value()); // Add the selected device
        r->showRoom(); // Re-show the room interface
    },
                              this);

    // Button to add a timer for a device
    Fl_Button *addTimerButton = new Fl_Button(100, 60, 200, 30, "Add Timer");
    addTimerButton->callback([](Fl_Widget *widget, void *data)
                              {
        Fl_Window *parent_window = widget->window(); // Hide the current window
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
                choice->add(device->getName());
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
                    Fl::add_timeout(seconds, timeoutCallback, selectedDevice);
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
            Fl::wait();
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
        yPosition += 40;
    }

    roomWindow->end();
    roomWindow->show();
}

// Adds a new device to the room based on user selection
void Room::addDevice(int selection)
{
    SmartDevice *device;

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
        return;
    }

    devices.push_back(device);
}

// Adds a device directly to the room
void Room::addDevice(SmartDevice *device)
{
    devices.push_back(device);
}

// Placeholder for removing a device from the room
void Room::removeDevice(std::shared_ptr<SmartDevice> device)
{
    // Logic to remove a device can be added here
}

// Equality operator to compare rooms by name
bool Room::operator==(Room &otherRoom)
{
    return roomName == otherRoom.roomName;
}

// Serializes the room data to JSON format
json Room::toJson() const
{
    json deviceArray = json::array();
    for (const auto &device : devices)
    {
        deviceArray.push_back(device->toJson());
    }
    return json{{"roomName", roomName}, {"devices", deviceArray}};
}

// Deserializes room data from JSON format
void Room::fromJson(const json &j)
{
    std::string roomName = j.at("roomName").get<std::string>();
    Room *room = new Room(roomName);
    for (const auto &deviceJson : j.at("devices"))
    {
        int typeInt = deviceJson.at("type").get<int>();
        std::cout << typeInt;
        room->addDevice(typeInt);
    }
}
