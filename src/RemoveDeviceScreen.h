/**
 * @file RemoveDeviceScreen.h
 * @brief Header file for the RemoveDeviceScreen class, providing a GUI for removing devices.
 */

#pragma once
#include <FL/fl_ask.H>
#include <string>
#include <FL/Fl_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

/**
 * @class RemoveDeviceScreen
 * @brief Represents the GUI for removing a smart device.
 * 
 * This class provides a drop-down menu to select a device for removal 
 * and a button to confirm the action.
 */
class RemoveDeviceScreen
{
public:
    /**
     * @brief Constructor for the RemoveDeviceScreen class.
     * 
     * Initializes the screen with the necessary UI components.
     */
    RemoveDeviceScreen();

    /**
     * @brief Displays the Remove Device Screen.
     */
    void show();

    /**
     * @brief Checks if the Remove Device Screen is currently visible.
     * 
     * @return True if the screen is visible, false otherwise.
     */
    bool shown();

    Fl_Choice *choice; ///< Drop-down menu for selecting a device to remove.

private:
    Fl_Window *window; ///< Main window for the Remove Device Screen.
    Fl_Button *button; ///< Button to confirm the device removal action.

    /**
     * @brief Callback function triggered when the "Enter" button is clicked.
     * 
     * Closes the screen upon confirmation of device removal.
     * 
     * @param widget Pointer to the widget triggering the callback.
     * @param data Pointer to the RemoveDeviceScreen instance.
     */
    static void login_cb(Fl_Widget *, void *);
};
