#pragma once
#include <iostream>
#include <string>
class SmartDevice{
	private:
		int id;
	public:
		std::string name;
		SmartDevice(int,std::string);
		//virtual void showDeviceInfo();
		bool operator==(const SmartDevice& other);
};
