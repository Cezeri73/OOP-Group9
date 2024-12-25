/**
 * @file AddRoomScreen.h
 * @brief Header file for the AddRoomScreen class, representing the user interface for adding rooms.
 */

#pragma once
#include <FL/fl_ask.H> 
#include <string>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

/**
 * @class AddRoomScreen
 * @brief Provides functionality to add a new room to the system via a user interface.
 */
class AddRoomScreen
{
public:
    /**
     * @brief Constructor for AddRoomScreen.
     */
    AddRoomScreen();

    /**
     * @brief Displays the Add Room Screen.
     */
    void show();

    /**
     * @brief Checks if the screen is currently visible.
     * @return True if visible, false otherwise.
     */
    bool shown();

private:
    Fl_Window *window; ///< Main window for the Add Room Screen.
    Fl_Input *roomName; ///< Input field for entering the room name.
    Fl_Button *button; ///< Button to confirm and add the room.

    /**
     * @brief Callback function for handling button click events.
     */
    static void login_cb(Fl_Widget *, void *);

    /**
     * @brief Internal function to handle room addition logic.
     */
    void handle_login();
};
