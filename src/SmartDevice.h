#ifndef SMART_DEVICE_H
#define SMART_DEVICE_H

#include <string>
#include <iostream>
class SmartDevice {
protected:
    std::string name;
    std::string status; // ON veya OFF durumunu belirtir

public:
    SmartDevice(std::string deviceName)
        : name(deviceName), status("OFF") {}

    virtual ~SmartDevice() = default;

    const char* getName(){
        	return name.c_str();
    }
    
    virtual std::string getStatus() const = 0; // Saf sanal metod
};

#endif // SMART_DEVICE_H
