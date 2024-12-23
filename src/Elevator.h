#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "SmartDevice.h"
#include <string>

class Elevator : public SmartDevice {
private:
    bool maintenanceRequired; // Asansörün bakıma ihtiyacı olup olmadığını belirten bayrak

public:
    Elevator(const std::string& deviceName);

    void checkMaintenance();
void deviceCallback(Fl_Widget*,void*) override;

    bool isMaintenanceRequired() const;

    std::string getStatus() const override;
};

#endif // ELEVATOR_H
