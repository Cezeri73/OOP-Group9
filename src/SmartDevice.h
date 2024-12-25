/**
 * @file SmartDevice.h
 * @brief Header file for the SmartDevice class, representing the base class for all smart devices.
 */

#ifndef SMART_DEVICE_H
#define SMART_DEVICE_H

#include <string>
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Text_Buffer.H>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

/**
 * @class SmartDevice
 * @brief Abstract base class for all smart devices in the smart home system.
 * 
 * Provides common functionality and properties for all smart devices,
 * such as notifications, status, and type management.
 */
class SmartDevice
{
protected:
    /**
     * @brief Enumeration representing the status of a smart device.
     */
    enum class Statu
    {
        ON,  ///< Device is turned on.
        OFF  ///< Device is turned off.
    };

    std::string name; ///< Name of the smart device.
    Statu statu;      ///< Current status of the device (ON or OFF).

public:
    /**
     * @brief Enumeration representing the type of a smart device.
     */
    enum class Type
    {
        Refrigerator,    ///< Represents a refrigerator device.
        Thermostat,      ///< Represents a thermostat device.
        Light,           ///< Represents a light device.
        WaterPurifier,   ///< Represents a water purifier device.
        Elevator,        ///< Represents an elevator device.
        Curtain,         ///< Represents a curtain device.
        SecurityCamera   ///< Represents a security camera device.
    };

    Type type; ///< Type of the smart device.
    static Fl_Text_Buffer *notificationBuffer; ///< Shared notification buffer for all devices.
    int hour; ///< Hour value for scheduling or timers.

    /**
     * @brief Constructor for the SmartDevice class.
     * 
     * Initializes a smart device with a given name and sets its status to OFF.
     * 
     * @param deviceName The name of the smart device.
     */
    SmartDevice(std::string deviceName)
        : name(deviceName), statu(Statu::OFF) {}

    /**
     * @brief Virtual destructor for the SmartDevice class.
     */
    virtual ~SmartDevice() = default;

    /**
     * @brief Retrieves the name of the smart device.
     * 
     * @return The name of the device as a C-style string.
     */
    const char *getName();

    /**
     * @brief Pure virtual function to handle device-specific actions.
     * 
     * Must be implemented by derived classes to handle user interaction via the GUI.
     * 
     * @param widget Pointer to the widget triggering the callback.
     * @param data User-defined data, typically the smart device instance.
     */
    virtual void deviceCallback(Fl_Widget *widget, void *data) = 0;

    /**
     * @brief Adds a notification message to the shared notification buffer.
     * 
     * @param message The notification message to add.
     */
    void addNotification(const std::string &message);

    /**
     * @brief Serializes the smart device to a JSON representation.
     * 
     * Converts the device's type into a JSON object for saving or transferring.
     * 
     * @return A JSON object containing the device's type.
     */
    json toJson() const;

    /**
     * @brief Deserializes a smart device from a JSON representation.
     * 
     * Recreates a smart device object based on the type specified in the JSON data.
     * 
     * @param j A JSON object containing the device's data.
     * @return A pointer to the newly created SmartDevice object, or nullptr if the type is unrecognized.
     */
    static SmartDevice *fromJson(const json &j);
};

#endif // SMART_DEVICE_H
