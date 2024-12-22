#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"

class Thermostat : public SmartDevice {
private:
    int temperature;

public:
    Thermostat(const std::string& deviceName, int initialTemp = 22)
        : SmartDevice(deviceName), temperature(initialTemp) {}

    void setTemperature(int temp) {
        temperature = temp;
        status = "ON"; // Sıcaklık ayarlandığında durumu ON yap
    }

    int getTemperature() const {
        return temperature;
    }

    std::string getStatus() const override {
        return "Thermostat is " + status + ", Temperature: " + std::to_string(temperature) + "°C";
    }
};

#endif // THERMOSTAT_H
