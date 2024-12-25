/**
 * @file Thermostat.h
 * @brief Header file for the Thermostat class, representing a smart thermostat device.
 */

#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"

/**
 * @class Thermostat
 * @brief Represents a smart thermostat in the smart home system.
 * 
 * The Thermostat class allows users to adjust and monitor the temperature 
 * and provides callbacks for user interaction via the GUI.
 */
class Thermostat : public SmartDevice
{
private:
    int temperature; ///< Current temperature of the thermostat in degrees Celsius.

public:
    /**
     * @brief Constructor for the Thermostat class.
     * 
     * Initializes the thermostat with a given name and an initial temperature.
     * 
     * @param deviceName The name of the thermostat device.
     * @param initialTemp The initial temperature to set for the thermostat.
     */
    Thermostat(const std::string &deviceName, int initialTemp);

    /**
     * @brief Sets the thermostat's temperature.
     * 
     * Updates the thermostat's temperature to the specified value and
     * triggers a notification after a specified time.
     * 
     * @param temp The desired temperature to set.
     */
    void setTemperature(int temp);

    /**
     * @brief Retrieves the current temperature of the thermostat.
     * 
     * @return The current temperature in degrees Celsius.
     */
    int getTemperature() const;

    /**
     * @brief Callback function for the thermostat's device button.
     * 
     * Displays a GUI for adjusting the thermostat's temperature and
     * provides an option to confirm the selection.
     * 
     * @param widget Pointer to the widget triggering the callback.
     * @param data Pointer to the Thermostat object.
     */
    void deviceCallback(Fl_Widget *widget, void *data) override;

    /**
     * @brief Confirms the selected temperature.
     * 
     * Updates the thermostat's temperature based on the slider's selected value.
     * 
     * @param widget Pointer to the triggering widget.
     * @param data Pointer to the Thermostat object.
     */
    static void confirm(Fl_Widget *widget, void *data);

    /**
     * @brief Callback function to generate a notification.
     * 
     * Adds a notification about the current temperature.
     * 
     * @param data Pointer to the Thermostat object triggering the notification.
     */
    static void notificationCallback(void *data);
};

#endif // THERMOSTAT_H
