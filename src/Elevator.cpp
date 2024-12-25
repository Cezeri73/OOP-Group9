/**
 * @file Elevator.cpp
 * @brief Implementation file for the Elevator class, representing a smart elevator device.
 */

#include "Elevator.h"
#include <time.h>

/**
 * @brief Constructor for the Elevator class.
 * 
 * Initializes the Elevator object with a device name and sets the maintenance
 * status to false. The device type is set to "Elevator."
 * 
 * @param deviceName The name of the elevator device.
 */
Elevator::Elevator(const std::string &deviceName)
    : SmartDevice(deviceName), maintenanceRequired(false) // Initialize base class and set maintenance status to false
{
    this->type = Type::Elevator; // Set the device type to "Elevator"
}

/**
 * @brief Callback function triggered when the elevator button is pressed.
 * 
 * Simulates a maintenance check for the elevator. There is an 8% chance that
 * maintenance is required. Notifications are added based on the result of the check.
 * 
 * @param widget Pointer to the widget triggering the callback.
 * @param data Pointer to user-defined data, expected to be an Elevator object.
 */
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
