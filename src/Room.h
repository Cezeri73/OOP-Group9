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
#include "AddDeviceScreen.h"
#include "Light.h"
#include "Thermostat.h"
#include "Curtain.h"
#include "SecurityCamera.h"
#include "WaterPurifier.h"
#include "Elevator.h"
#include "Refrigerator.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Room{
	private:
		std::vector<SmartDevice*> devices;
		AddDeviceScreen ads;		
	public:
		static std::vector<Room*> allRooms;	
	        std::string roomName;
		Room(std::string&);
		void showRoom();
		void addDevice(int);
		void removeDevice(std::shared_ptr<SmartDevice>);
		bool operator==(Room&);
		json toJson() const;
		static void fromJson(const json& j);
		void addDevice(SmartDevice*);
};
