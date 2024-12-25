#include "Room.h"
std::vector<Room*> Room::allRooms;

Room::Room(std::string &name) :
		roomName(name) {
	allRooms.push_back(this);
}


void Room::showRoom() {
	std::string name = roomName;
	Fl_Window *roomWindow = new Fl_Window(400, 400, name.c_str());
	Fl_Button *addDeviceButton = new Fl_Button(100, 20, 200, 30, "Add Device");
	Fl_Button *addTimerButton = new Fl_Button(100, 60, 200, 30, "Add Timer");

	addDeviceButton->callback([](Fl_Widget *widget, void *data) {
		Fl_Window *parent_window = widget->window();
		parent_window->hide();

		Room *r = static_cast<Room*>(data);
		r->ads.show();
		while (r->ads.shown()) {
			Fl::wait();
		}
		r->addDevice(r->ads.choice->value());
		r->showRoom();
	},this);


	addTimerButton->callback([](Fl_Widget *widget, void *data) {
		Fl_Window *parent_window = widget->window();
		parent_window->hide();

		Room *r = static_cast<Room*>(data);
		Fl_Window *window = new Fl_Window(300, 200, "Add Timer Screen");

		Fl_Choice *choice = new Fl_Choice(100, 50, 100, 30, "Device:");
		if (!r->devices.empty()) {
			for (const auto &device : r->devices) {
				choice->add(device->getName());
			}
		}

		Fl_Input *timeInput = new Fl_Input(100, 90, 100, 30, "Hour:");
		Fl_Button *button = new Fl_Button(110, 130, 80, 30, "Enter");

		button->callback([](Fl_Widget *widget, void *data) {
			auto *callbackData =
					static_cast<std::pair<Room*, Fl_Choice*>*>(data);
			Room *room = callbackData->first;
			Fl_Choice *deviceChoice = callbackData->second;

			Fl_Input *timeInput =
					static_cast<Fl_Input*>(widget->parent()->child(1)); // Time input widget
			const char *timeStr = timeInput->value();
			int seconds = std::atoi(timeStr); // Convert entered time to integer

			if (deviceChoice->value() >= 0 && seconds > 0) {
				SmartDevice *selectedDevice = room->devices.at(deviceChoice->value());
				// Callback for Fl::add_timeout
				auto timeoutCallback = [](void *data) {
					SmartDevice *device = static_cast<SmartDevice*>(data);

					// Simulate a widget and window for deviceCallback
					Fl_Button tempButton(0, 0, 0, 0, "Temp"); // Dummy button
					Fl_Window tempWindow(0, 0, 100, 100, "Temp Window"); // Dummy window
					tempButton.parent(&tempWindow); // Link the button to the dummy window
					device->deviceCallback(&tempButton, device); // Trigger the device callback
					device->addNotification("Device turned on after timer!");

					// Add any other action you want for the device
				};
				if(selectedDevice->type==SmartDevice::Type::Thermostat){
					Fl_Button *tempButton = new Fl_Button(0, 0, 0, 0, "Temp");
					selectedDevice->time=seconds;
					selectedDevice->deviceCallback(tempButton, selectedDevice);

				}
				else{
					Fl::add_timeout(seconds, timeoutCallback, selectedDevice);
				}
			}
			
			widget->window()->hide(); // Close the timer window
		}, new std::pair<Room*, Fl_Choice*>(r, choice));

		window->end();
		window->show();

		while (window->visible()) {
			Fl::wait();
		}

		r->showRoom(); // Show the main room window again
	}, this);

	int yPosition = 100;
	for (size_t i = 0; i < devices.size(); ++i) {
		Fl_Button *deviceButton = new Fl_Button(100, yPosition, 200, 30,
				devices[i]->getName());
		deviceButton->callback([](Fl_Widget *widget, void *data) {
			SmartDevice *dev = static_cast<SmartDevice*>(data);
			dev->deviceCallback(widget, data);  // Call deviceCallback method
		},
		devices[i] // Pass the device instance (which is Light or its derived class)
				);
		yPosition += 40;
	}
	roomWindow->end();
	roomWindow->show();
}

void Room::addDevice(int selection) {
	SmartDevice *device;

	switch (selection) {
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
void Room::addDevice(SmartDevice* device){
	devices.push_back(device);
}

void Room::removeDevice(std::shared_ptr<SmartDevice> device) {
//	devices.erase(std::remove(devices.begin(), devices.end(),device), devices.end());
}
bool Room::operator==(Room &otherRoom) {
	return roomName == otherRoom.roomName;
}

json Room::toJson() const{
	json deviceArray = json::array();
	for(const auto& device : devices){
		deviceArray.push_back(device->toJson());
	}
	return json{{"roomName",roomName},{"devices",deviceArray}};
}
void Room::fromJson(const json& j){
	std::string roomName = j.at("roomName").get<std::string>();
	Room* room = new Room(roomName);
	for(const auto& deviceJson : j.at("devices")){
		int typeInt = deviceJson.at("type").get<int>();
		std::cout<<typeInt;
		room->addDevice(typeInt);
	}
}
