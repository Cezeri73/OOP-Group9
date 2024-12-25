/**
 * @file Light.h
 * @brief Header file for the Light class.
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "SmartDevice.h"
#include <string>

/**
 * @class Light
 * @brief Represents a smart light device.
 */
class Light : public SmartDevice {
public:
    /**
     * @brief Constructor to initialize a Light device.
     * @param deviceName Name of the light device.
     */
    Light(const std::string& deviceName);

    /**
     * @brief Turns the light on.
     */
    void turnOn();

    /**
     * @brief Turns the light off.
     */
    void turnOff();

    /**
     * @brief Callback function for light-related actions.
     */
    void deviceCallback(Fl_Widget*,void*) override;

    /**
     * @brief Static callback function for light notifications.
     */
    static void notificationCallback(void* data);
};




#endif