#include "Controller.h"

Controller::Controller(SmartDevice* dev) : device(dev) {}

void Controller::toggleDevice() {
    device->toggle();
}
