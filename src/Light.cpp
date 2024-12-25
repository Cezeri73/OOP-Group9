#include "Light.h"

// Constructor to initialize the Light object
Light::Light(const std::string &deviceName) : SmartDevice(deviceName)
{
    this->type = Type::Light; // Set the device type to "Light"
}

// Callback function to handle light notifications
void Light::notificationCallback(void *data)
{
    // Cast the `data` pointer to a `Light` object
    Light *light = static_cast<Light *>(data);

    // Check the light's status and add an appropriate notification
    light->statu == Statu::ON ? light->addNotification("Light turned ON.") : light->addNotification("Light turned OFF.");
}

// Callback function for the light button
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

// Turn the light on by changing the status to ON
void Light::turnOn()
{
    statu = Statu::ON; // Set the light status to ON
}

// Turn the light off by changing the status to OFF
void Light::turnOff()
{
    statu = Statu::OFF; // Set the light status to OFF
}
