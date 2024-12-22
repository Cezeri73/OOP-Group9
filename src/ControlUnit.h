#ifndef CONTROLLERUNIT_H
#define CONTROLLERUNIT_H

#include <iostream>

class ControllerUnit {
public:
    void executeAction() { std::cout << "Executing scheduled action...\n"; }
    void scheduleAction() { std::cout << "Scheduling an action...\n"; }
};

#endif // CONTROLLERUNIT_H

