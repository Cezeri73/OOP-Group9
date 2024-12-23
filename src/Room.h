#pragma once

#include "SmartDevice.h"
#include "Light.h"
#include <iostream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

class Room{
	private:
		std::vector<SmartDevice*> devices;
	public:
		std::string roomName;
		Room(std::string);
		void showRoom();
		void addDevice(SmartDevice*);
		void removeDevice(std::shared_ptr<SmartDevice>);
		bool operator==(Room&);
};
