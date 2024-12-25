#ifndef SMARTHOMESYSTEM_H
#define SMARTHOMESYSTEM_H

#include "SmartDevice.h"
#include "NotificationSystem.h"
#include "ControllerUnit.h"
#include <vector>
#include <iostream>

class SmartHomeSystem {
private:
    std::vector<SmartDevice*> devices;
    NotificationSystem notificationSystem;

public:
    SmartDevice* getDevice(const std::string& name) {
        for (auto device : devices) {
            if (device->getName() == name) {
                return device;
            }
        }
        return nullptr;
    }
    void addDevice(SmartDevice* device) { devices.push_back(device); }

    void showDevices() {
        for (auto device : devices) {
            std::cout << "Device: " << device->getName() << " | Status: " << device->getStatus() << std::endl;
        }
    }

    void notifyAll(const std::string& message) { notificationSystem.notify(message); }
    NotificationSystem& getNotificationSystem() { return notificationSystem; }
};

#endif // SMARTHOMESYSTEM_H

