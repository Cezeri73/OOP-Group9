#ifndef CONTROLLER_UNIT_H
#define CONTROLLER_UNIT_H

#include "SmartDevice.h"

class ControllerUnit {
public:
    void controlDevice(SmartDevice* device, const std::string& command) {
        if (command == "ON") {
            device->getStatus(); // Örnek işlev çağrısı
        } else if (command == "OFF") {
            device->getStatus(); // Örnek işlev çağrısı
        }
    }
};

#endif // CONTROLLER_UNIT_H

