#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "SmartDevice.h"
#include <string>

class Elevator : public SmartDevice {
private:
    bool maintenanceRequired; 

public:
    Elevator(const std::string& deviceName);
    void deviceCallback(Fl_Widget*,void*) override;
};

#endif 
