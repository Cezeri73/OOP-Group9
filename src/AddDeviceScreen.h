/**
 * @file AddDeviceScreen.h
 * @brief Header file for the AddDeviceScreen class.
 */

#pragma once
#include <FL/fl_ask.H> 
#include <string>
#include <FL/Fl_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

/**
 * @class AddDeviceScreen
 * @brief Represents the screen for adding new devices to the system.
 */
class AddDeviceScreen
{
public:
    /**
     * @brief Constructor to initialize the Add Device Screen.
     */
    AddDeviceScreen();

    /**
     * @brief Displays the Add Device Screen.
     */
    void show();

    /**
     * @brief Checks if the screen is currently visible.
     * @return True if the screen is visible, false otherwise.
     */
    bool shown();

    /**
     * @brief Dropdown menu to select the device type.
     */
    Fl_Choice *choice;

private:
    Fl_Window *window; ///< Pointer to the main window of the screen.
    Fl_Button *button; ///< Button to confirm device selection.

    /**
     * @brief Callback function for the "Enter" button.
     */
    static void login_cb(Fl_Widget *, void *);

    /**
     * @brief Placeholder method for handling login functionality.
     */
    void handle_login();
};
