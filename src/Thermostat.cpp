#include "Thermostat.h"
#include <FL/Fl_Value_Output.H>

// Constructor to initialize the Thermostat object
Thermostat::Thermostat(const std::string &deviceName, int initialTemp = 22)
    : SmartDevice(deviceName)
{
    this->type = Type::Thermostat; // Set the device type to "Thermostat"
    temperature = 22; // Initialize temperature to 22°C
}

// Callback function to handle thermostat notifications
void Thermostat::notificationCallback(void *data)
{
    // Cast the `data` pointer to a `Thermostat` object
    Thermostat *thermostat = static_cast<Thermostat *>(data);

    // Add a notification with the current temperature
    thermostat->addNotification("Thermostat temperature set to " + std::to_string(thermostat->getTemperature()) + " °C.");
    thermostat->hour = 0; // Reset the hour value (not sure about its usage in this context)
}

// Function to set the thermostat's temperature
void Thermostat::setTemperature(int temp)
{
    temperature = temp; // Set the temperature to the provided value
    statu = Statu::ON;  // Set the status to ON when the temperature is set

    // Add a timeout to trigger the notification after the specified time
    Fl::add_timeout(this->hour, notificationCallback, this);
}

// Getter function to retrieve the thermostat's current temperature
int Thermostat::getTemperature() const
{
    return temperature; // Return the current temperature
}

int degree = 0; // Global variable to hold the slider value (temperature)

// Callback function to handle the confirmation of the temperature setting
void Thermostat::confirm(Fl_Widget *widget, void *data)
{
    Thermostat *thermostat = static_cast<Thermostat *>(data);
    thermostat->setTemperature(degree); // Set the temperature to the selected value (degree)
}

// Callback function for the thermostat's device button
void Thermostat::deviceCallback(Fl_Widget *widget, void *data)
{
    Thermostat *thermostat = static_cast<Thermostat *>(data);

    // Create a new window for the thermostat settings
    Fl_Window *thermoWindow = new Fl_Window(600, 300, "Thermostat");
    thermoWindow->color(FL_GRAY); // Set the window's background color

    // Create a horizontal slider to control the temperature
    Fl_Slider *thermoSlider = new Fl_Slider(150, 120, 300, 30);
    thermoSlider->type(FL_HORIZONTAL); // Make it a horizontal slider
    thermoSlider->minimum(0); // Set the minimum value to 0°C
    thermoSlider->maximum(100); // Set the maximum value to 100°C
    thermoSlider->value(thermostat->getTemperature()); // Set the initial value to the current temperature
    thermoSlider->step(1); // Set the step size to 1°C

    // Create a value output field to display the selected temperature
    Fl_Value_Output *valueOutput = new Fl_Value_Output(250, 160, 100, 30);
    valueOutput->label("Temperature:"); // Label for the output field
    valueOutput->textsize(16); // Set the text size
    valueOutput->align(FL_ALIGN_CENTER); // Center-align the text
    valueOutput->value(thermoSlider->value()); // Set the initial value to the slider's value

    // Set the thermostat object as user data for the slider
    thermoSlider->user_data(thermostat);

    // Callback function for the slider to update the value output and store the selected temperature
    thermoSlider->callback([](Fl_Widget *widget, void *data)
                           {
                               Fl_Slider *slider = static_cast<Fl_Slider *>(widget);
                               Fl_Value_Output *valueOutput = static_cast<Fl_Value_Output *>(data);

                               valueOutput->value(slider->value()); // Update the value output
                               degree = slider->value(); // Store the selected temperature (degree) globally
                           },
                           valueOutput);

    // Create a button to confirm the temperature setting
    Fl_Button *confirmButton = new Fl_Button(250, 200, 100, 40, "Confirm");
    confirmButton->callback(confirm, thermostat); // Set the confirm callback

    // End the window and show it
    thermoWindow->end();
    thermoWindow->show();
};
