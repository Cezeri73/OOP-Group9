#ifndef SMARTDEVICEFACTORY_H
#define SMARTDEVICEFACTORY_H

#include "SmartDevice.h"
#include "Curtain.h"
#include "Light.h"

class SmartDeviceFactory {
public:
    static SmartDevice* createDevice(const std::string& type, const std::string& name);
};

#endif
