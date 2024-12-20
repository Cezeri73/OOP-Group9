#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "SmartDevice.h"

class Controller {
private:
    SmartDevice* device;

public:
    Controller(SmartDevice* dev);
    void toggleDevice();
};

#endif
