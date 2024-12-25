/**
 * @file AddDeviceScreen.cpp
 * @brief Implementation of the AddDeviceScreen class.
 */

#include "AddDeviceScreen.h"

/**
 * @brief Constructor to initialize the Add Device Screen components.
 */
AddDeviceScreen::AddDeviceScreen()
{
    window = new Fl_Window(340, 220, "Add Device");
    choice = new Fl_Choice(120, 90, 210, 25, "Device Type:");
    choice->add("Light|Curtain|Thermostat|Security Camera|Refrigerator|Elevator|Water Purifier");
    button = new Fl_Button(200, 160, 100, 25, "Enter");
    button->callback(login_cb, this);
    window->end();
}

/**
 * @brief Displays the Add Device Screen to the user.
 */
void AddDeviceScreen::show()
{
    window->show();
}

/**
 * @brief Checks if the Add Device Screen is visible.
 * @return True if the screen is visible, false otherwise.
 */
bool AddDeviceScreen::shown()
{
    return window->shown();
}

/**
 * @brief Callback function triggered when the "Enter" button is clicked.
 * @param widget Pointer to the button widget.
 * @param data Pointer to user-defined data.
 */
void AddDeviceScreen::login_cb(Fl_Widget *widget, void *data)
{
    AddDeviceScreen *self = static_cast<AddDeviceScreen *>(data);
    self->handle_login();
}

/**
 * @brief Handles the logic when the "Enter" button is clicked.
 */
void AddDeviceScreen::handle_login()
{
    fl_alert("Device type: %s", choice->text());
    window->hide();
}
