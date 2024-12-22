#include "SmartDevice.h"

SmartDevice::SmartDevice(int id,std::string name):id(id),name(name){};

bool SmartDevice::operator==(const SmartDevice& other){
	return id == other.id;
}
