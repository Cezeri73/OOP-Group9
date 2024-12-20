#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>
#include <vector>
#include "NotificationSystem.h"

class SmartDevice {
protected:
    std::string name;
    bool status;
    std::vector<Observer*> observers;

public:
    SmartDevice(const std::string& deviceName);
    virtual ~SmartDevice() = default;

    void addObserver(Observer* observer);
    void notifyObservers(const std::string& message);

    virtual void toggle() = 0;
};

#endif
