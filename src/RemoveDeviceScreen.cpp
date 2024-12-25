#include "RemoveDeviceScreen.h"

// Constructor to initialize the RemoveDeviceScreen
RemoveDeviceScreen::RemoveDeviceScreen()
{
    // Create a window with dimensions 300x200 and a title "Device Add Screen"
    window = new Fl_Window(300, 200, "Device Add Screen");

    // Create a drop-down choice menu to allow the user to select a device to remove
    choice = new Fl_Choice(100, 50, 100, 30);
    choice->add("Refrigerator");
    choice->add("Thermostat");
    choice->add("Light");
    choice->add("WaterPurifier");
    choice->add("Elevator");
    choice->add("Curtain");
    choice->add("Camera");

    // Create a button labeled "Enter" that will trigger a callback when clicked
    button = new Fl_Button(110, 130, 80, 30, "Enter");

    // Set the callback function for the button click event
    button->callback(login_cb, this);

    // End the window definition, indicating that the window has been fully defined
    window->end();
}

// Show the window to the user
void RemoveDeviceScreen::show()
{
    window->show(); // Display the window
}

// Return whether the window is currently visible
bool RemoveDeviceScreen::shown()
{
    return window->visible(); // Check if the window is currently visible
}

// Callback function when the "Enter" button is clicked
void RemoveDeviceScreen::login_cb(Fl_Widget *widget, void *data)
{
    // Get the parent window of the widget (button)
    Fl_Window *parent_window = widget->window();

    // Hide the parent window (close the screen after clicking "Enter")
    parent_window->hide();
}
