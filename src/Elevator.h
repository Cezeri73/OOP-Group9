#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "SmartDevice.h"
#include <string>

class Elevator : public SmartDevice {
private:
    bool maintenanceRequired; // Asansörün bakıma ihtiyacı olup olmadığını belirten bayrak

public:
    Elevator(const std::string& deviceName)
        : SmartDevice(deviceName), maintenanceRequired(false) {}

    void checkMaintenance() {
        // Rastgele bir değer ile bakım durumunu kontrol et
        maintenanceRequired = (std::rand() % 2 == 0);
    }

    bool isMaintenanceRequired() const {
        return maintenanceRequired;
    }

    std::string getStatus() const override {
        return "Elevator Status: " + std::string(maintenanceRequired ? "Maintenance Required" : "Operational");
    }
};

#endif // ELEVATOR_H
