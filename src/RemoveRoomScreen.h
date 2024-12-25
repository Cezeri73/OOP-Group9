/**
 * @file RemoveRoomScreen.h
 * @brief Header file for the RemoveRoomScreen class, providing a GUI for removing rooms.
 */

#pragma once
#include <FL/fl_ask.H>
#include <string>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

/**
 * @class RemoveRoomScreen
 * @brief Represents the GUI for removing a room in the smart home system.
 * 
 * This class provides an input field for entering the room name and a button 
 * to confirm the removal action.
 */
class RemoveRoomScreen
{
public:
    /**
     * @brief Constructor for the RemoveRoomScreen class.
     * 
     * Initializes the screen with the necessary UI components.
     */
    RemoveRoomScreen();

    /**
     * @brief Displays the Remove Room Screen.
     */
    void show();

    /**
     * @brief Checks if the Remove Room Screen is currently visible.
     * 
     * @return True if the screen is visible, false otherwise.
     */
    bool shown();

private:
    Fl_Window *window; ///< Main window for the Remove Room Screen.
    Fl_Input *roomName; ///< Input field for entering the name of the room to be removed.
    Fl_Button *button; ///< Button to confirm the room removal action.

    /**
     * @brief Static callback function triggered when the "Enter" button is clicked.
     * 
     * Calls the `handle_login` method to process the room removal logic.
     * 
     * @param widget Pointer to the widget triggering the callback.
     * @param data Pointer to the RemoveRoomScreen instance.
     */
    static void login_cb(Fl_Widget *, void *);

    /**
     * @brief Handles the logic for removing a room.
     * 
     * Retrieves the room name entered by the user and removes the corresponding
     * room from the list of all rooms.
     */
    void handle_login();
};
