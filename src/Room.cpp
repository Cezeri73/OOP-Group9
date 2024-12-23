#include "Room.h"


Room::Room(std::string name):roomName(name){};

void Room::showRoom(){
	std::string name = roomName;
	Fl_Window* roomWindow = new Fl_Window(400, 400, name.c_str());
	int yPosition = 20;
        for (size_t i = 0; i < devices.size(); ++i) {
	    	Fl_Button* deviceButton = new Fl_Button(100, yPosition, 200, 30, devices[i]->getName());
		deviceButton->callback(
        	[](Fl_Widget* widget, void* data) {
            		SmartDevice* dev = static_cast<SmartDevice*>(data);
			dev->deviceCallback(widget, data);  // Call deviceCallback method
        	},
        	devices[i]  // Pass the device instance (which is Light or its derived class)
    		);
            yPosition += 40; 
        }
	roomWindow->end();
	roomWindow->show();
}

void Room::addDevice(SmartDevice* device){
	devices.push_back(device);
}
void Room::removeDevice(std::shared_ptr<SmartDevice> device){
//	devices.erase(std::remove(devices.begin(), devices.end(),device), devices.end());
}
bool Room::operator==(Room& otherRoom){
	return roomName == otherRoom.roomName;
}
