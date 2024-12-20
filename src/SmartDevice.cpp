#include "SmartDevice.h"

SmartDevice::SmartDevice(const std::string& deviceName) : name(deviceName), status(false) {}

void SmartDevice::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void SmartDevice::notifyObservers(const std::string& message) {
    for (Observer* observer : observers) {
        observer->update(message);
    }
}
