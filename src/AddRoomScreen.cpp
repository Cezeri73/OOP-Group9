/**
 * @file AddRoomScreen.cpp
 * @brief Implementation of the AddRoomScreen class.
 */

#include "AddRoomScreen.h"

/**
 * @brief Constructor to initialize the Add Room Screen components.
 */
AddRoomScreen::AddRoomScreen()
{
    window = new Fl_Window(340, 220, "Add Room");
    roomName = new Fl_Input(120, 90, 210, 25, "Room Name:");
    button = new Fl_Button(200, 160, 100, 25, "Enter");
    button->callback(login_cb, this);
    window->end();
}

/**
 * @brief Displays the Add Room Screen to the user.
 */
void AddRoomScreen::show()
{
    window->show();
}

/**
 * @brief Checks if the Add Room Screen is visible.
 * @return True if the screen is visible, false otherwise.
 */
bool AddRoomScreen::shown()
{
    return window->shown();
}

/**
 * @brief Callback function triggered when the "Enter" button is clicked.
 * @param widget Pointer to the button widget.
 * @param data Pointer to user-defined data.
 */
void AddRoomScreen::login_cb(Fl_Widget *widget, void *data)
{
    AddRoomScreen *self = static_cast<AddRoomScreen *>(data);
    self->handle_login();
}

/**
 * @brief Handles the logic when the "Enter" button is clicked.
 */
void AddRoomScreen::handle_login()
{
    fl_alert("Room name: %s", roomName->value());
    window->hide();
}
