#include "AddDeviceScreen.h"

// Constructor to initialize the Add Device Screen
AddDeviceScreen::AddDeviceScreen()
{
    // Create a new window for adding devices
    window = new Fl_Window(300, 200, "Device Add Screen");

    // Create a dropdown (choice) widget to select device type
    choice = new Fl_Choice(100, 50, 100, 30);
    choice->add("Refrigerator");   // Add Refrigerator option
    choice->add("Thermostat");     // Add Thermostat option
    choice->add("Light");          // Add Light option
    choice->add("WaterPurifier");  // Add Water Purifier option
    choice->add("Elevator");       // Add Elevator option
    choice->add("Curtain");        // Add Curtain option
    choice->add("Camera");         // Add Camera option

    // Create an "Enter" button for confirming the device selection
    button = new Fl_Button(110, 130, 80, 30, "Enter");
    button->callback(login_cb, this); // Set the callback function for the button

    // Finalize and display the window
    window->end();
}

// Method to show the Add Device Screen
void AddDeviceScreen::show()
{
    window->show(); // Display the window
}

// Method to check if the window is currently visible
bool AddDeviceScreen::shown()
{
    return window->visible(); // Return the visibility status of the window
}

// Callback function for the "Enter" button
void AddDeviceScreen::login_cb(Fl_Widget *widget, void *data)
{
    // Close the parent window when the button is clicked
    Fl_Window *parent_window = widget->window();
    parent_window->hide();
}

// Placeholder for handling login (not implemented)
void AddDeviceScreen::handle_login()
{
    // Functionality to handle login (if needed) can be added here
}
