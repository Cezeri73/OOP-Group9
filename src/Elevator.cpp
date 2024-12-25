#include "Elevator.h"
#include <time.h>

Elevator::Elevator(const std::string &deviceName)
    : SmartDevice(deviceName), maintenanceRequired(false)
{
    this->type = Type::Elevator;
}

void Elevator::deviceCallback(Fl_Widget *widget, void *data)
{
    Elevator *elevator = static_cast<Elevator *>(data);
    srand(time(NULL));
    int num = rand() % 100 + 1;
    if (num <= 8)
    {
        addNotification("Elevator maintenance required!");
        maintenanceRequired = true;
    }
    else
    {
        addNotification("Elevator is functioning well.");
        maintenanceRequired = false;
    }
};