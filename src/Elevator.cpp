#include "Elevator.h"
#include <time.h>

// Constructor to initialize the Elevator object
Elevator::Elevator(const std::string &deviceName)
    : SmartDevice(deviceName), maintenanceRequired(false) // Initialize base class and set maintenance status to false
{
    this->type = Type::Elevator; // Set the device type to "Elevator"
}

// Callback function for the elevator button
void Elevator::deviceCallback(Fl_Widget *widget, void *data)
{
    // Cast the `data` pointer to an `Elevator` object
    Elevator *elevator = static_cast<Elevator *>(data);

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random number between 1 and 100
    int num = rand() % 100 + 1;

    // Simulate a maintenance check with an 8% chance of requiring maintenance
    if (num <= 8) // If the random number is 8 or less
    {
        addNotification("Elevator maintenance required!"); // Notify the user about maintenance
        maintenanceRequired = true; // Set the maintenance flag to true
    }
    else // Otherwise, the elevator is functioning well
    {
        addNotification("Elevator is functioning well."); // Notify the user that the elevator is fine
        maintenanceRequired = false; // Set the maintenance flag to false
    }
};
