#ifndef LIGHT_H
#define LIGHT_H

#include "SmartDevice.h"
#include <string>

class Light : public SmartDevice {
private:
    int brightness;

public:
void turnOn() {
    status = "ON";
}

void turnOff() {
    status = "OFF";
}


    Light(const std::string& deviceName, int initialBrightness = 70)
        : SmartDevice(deviceName), brightness(initialBrightness) {}
        

    void adjustBrightness(int level) {
        brightness = (level >= 0 && level <= 100) ? level : brightness;
    }

    std::string getStatus() const override {
        return std::string((status == "ON") ? "ON" : "OFF") + ", Brightness: " + std::to_string(brightness) + "%";
    }
};

#endif // LIGHT_H

