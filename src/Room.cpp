#include "Room.h"
std::vector<Room*> Room::allRooms;

Room::Room(std::string& name):roomName(name){
	allRooms.push_back(this);
};

void Room::showRoom(){
	std::string name = roomName;
	Fl_Window* roomWindow = new Fl_Window(400, 400, name.c_str());
	Fl_Button* addDeviceButton = new Fl_Button(100,20,200,30,"Add Device");
	addDeviceButton->callback(
			[](Fl_Widget* widget, void* data){
				Fl_Window *parent_window = widget->window();
				parent_window->hide();
			
				Room* r = static_cast<Room*>(data);
				r->ads.show();
				while(r->ads.shown()){
					Fl::wait();
				}
				r->addDevice(r->ads.choice->value());
				r->showRoom();
			},this);
	
	int yPosition = 60;
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

void Room::addDevice(int selection){
	SmartDevice* device;

	switch(selection) {
	    case 0:
	        device = new Light("Light");
	        break;
	    case 1:
	        device = new Thermostat("Thermostat",22);
	        break;
	    case 2:
	        device = new Refrigerator("Refrigerator");
	        break;
	    case 3:
	        device = new WaterPurifier("Water Purifier");
	        break;
	    case 4:
	        device = new Elevator("Elevator");
	        break;
	    case 5:
	        device = new SecurityCamera("Camera");
	        break;
	    case 6:
	        device = new Curtain("Curtain");
	        break;
	    case -1:
	        return;
	}
	
	
	devices.push_back(device);
}
void Room::removeDevice(std::shared_ptr<SmartDevice> device){
//	devices.erase(std::remove(devices.begin(), devices.end(),device), devices.end());
}
bool Room::operator==(Room& otherRoom){
	return roomName == otherRoom.roomName;
}
