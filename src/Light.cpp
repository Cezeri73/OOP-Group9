/**
 * @file Light.cpp
 * @brief Implementation of the Light class, representing a smart light device.
 */

#include "Light.h"

/**
 * @brief Constructor for the Light class.
 * 
 * Initializes the Light object with a device name and sets the device type to "Light."
 * 
 * @param deviceName The name of the light device.
 */
Light::Light(const std::string &deviceName) : SmartDevice(deviceName)
{
    this->type = Type::Light; // Set the device type to "Light"
}

/**
 * @brief Callback function for handling light notifications.
 * 
 * Generates a notification based on the current status of the light (ON or OFF).
 * 
 * @param data Pointer to the Light object triggering the callback.
 */
void Light::notificationCallback(void *data)
{
    // Cast the `data` pointer to a `Light` object
    Light *light = static_cast<Light *>(data);

    // Check the light's status and add an appropriate notification
    light->statu == Statu::ON ? light->addNotification("Light turned ON.") : light->addNotification("Light turned OFF.");
}

/**
 * @brief Callback function triggered by the light button.
 * 
 * Toggles the light's status between ON and OFF, updates the button appearance,
 * and generates a corresponding notification.
 * 
 * @param widget Pointer to the widget triggering the callback.
 * @param data Pointer to user-defined data, expected to be a Light object.
 */
void Light::deviceCallback(Fl_Widget *widget, void *data)
{
    // Cast the `data` pointer to a `Light` object
    Light *light = static_cast<Light *>(data);

    // Cast the widget to a `Fl_Button` and `Fl_Window` for further use
    Fl_Button *button = static_cast<Fl_Button *>(widget);
    Fl_Window *window = static_cast<Fl_Window *>(widget->window());

    // If the light is off, turn it on; otherwise, turn it off
    if (statu == Statu::OFF) // If the light is off
    {
        light->turnOn(); // Turn the light on
        button->color(FL_GREEN); // Change button color to green (indicating the light is on)
        button->labelcolor(FL_WHITE); // Set button label color to white for contrast
        notificationCallback(data); // Call notification callback to notify the light is on
    }
    else // If the light is on
    {
        light->turnOff(); // Turn the light off
        button->color(FL_RED); // Change button color to red (indicating the light is off)
        button->labelcolor(FL_WHITE); // Set button label color to white for contrast
        notificationCallback(data); // Call notification callback to notify the light is off
    }

    // Redraw the window and button to reflect the updated state
    window->redraw();
    button->redraw();
}

/**
 * @brief Turns the light on by updating its status.
 */
void Light::turnOn()
{
    statu = Statu::ON; // Set the light status to ON
}

/**
 * @brief Turns the light off by updating its status.
 */
void Light::turnOff()
{
    statu = Statu::OFF; // Set the light status to OFF
}
