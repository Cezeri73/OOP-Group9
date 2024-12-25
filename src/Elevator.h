/**
 * @file Elevator.h
 * @brief Header file for the Elevator class.
 */

#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "SmartDevice.h"
#include <string>

/**
 * @class Elevator
 * @brief Represents a smart elevator device.
 */
class Elevator : public SmartDevice {
private:
    bool maintenanceRequired; ///< Indicates if the elevator needs maintenance.

public:
    /**
     * @brief Constructor to initialize an Elevator device.
     * @param deviceName Name of the elevator device.
     */
    Elevator(const std::string& deviceName);

    /**
     * @brief Callback function for elevator-related actions.
     */
    void deviceCallback(Fl_Widget*,void*) override;
};

#endif 
