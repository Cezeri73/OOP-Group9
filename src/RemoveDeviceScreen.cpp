/**
 * @file RemoveDeviceScreen.cpp
 * @brief Implementation of the RemoveDeviceScreen class, providing a GUI for removing devices.
 */

#include "RemoveDeviceScreen.h"

/**
 * @brief Constructor for the RemoveDeviceScreen class.
 * 
 * Initializes the GUI components for removing a device, including a drop-down
 * menu to select a device and a button to confirm the action.
 */
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

/**
 * @brief Displays the Remove Device Screen.
 * 
 * This method shows the window to the user.
 */
void RemoveDeviceScreen::show()
{
    window->show(); // Display the window
}

/**
 * @brief Checks if the Remove Device Screen is currently visible.
 * 
 * @return True if the window is visible, false otherwise.
 */
bool RemoveDeviceScreen::shown()
{
    return window->visible(); // Check if the window is currently visible
}

/**
 * @brief Callback function triggered when the "Enter" button is clicked.
 * 
 * Closes the Remove Device Screen by hiding its parent window.
 * 
 * @param widget Pointer to the widget triggering the callback.
 * @param data Pointer to user-defined data, expected to be a RemoveDeviceScreen object.
 */
void RemoveDeviceScreen::login_cb(Fl_Widget *widget, void *data)
{
    // Get the parent window of the widget (button)
    Fl_Window *parent_window = widget->window();

    // Hide the parent window (close the screen after clicking "Enter")
    parent_window->hide();
}
