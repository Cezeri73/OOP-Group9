/**
 * @file MainWindow.h
 * @brief Header file for the MainWindow class, providing the main interface for managing rooms and smart devices.
 */

#pragma once

#include <chrono>
#include <thread>
#include <iostream>
#include "Room.h"
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <vector>
#include <algorithm>
#include "AddRoomScreen.h"
#include "RemoveRoomScreen.h"
#include <fstream>

/**
 * @class MainWindow
 * @brief Represents the main application window for the smart home control panel.
 * 
 * This class provides functionality to manage rooms, update UI components, 
 * and save or load the program's state to/from a file.
 */
class MainWindow : public Fl_Window
{
private:
    static AddRoomScreen addRoomScreen; ///< Static instance of the AddRoomScreen.
    static RemoveRoomScreen removeRoomScreen; ///< Static instance of the RemoveRoomScreen.
    Fl_Button *addRoomButton; ///< Button to add a new room.
    Fl_Button *removeRoomButton; ///< Button to remove an existing room.

    /**
     * @brief Saves the current state of the program to a file.
     * 
     * Converts all rooms to JSON format and writes the data to a file.
     */
    void saveProgram();

    /**
     * @brief Loads the program's state from a file.
     * 
     * Reads JSON data from the file and recreates the rooms.
     */
    void loadProgram();

public:
    /**
     * @brief Constructor for the MainWindow class.
     * 
     * Initializes the main window with specified dimensions and a title.
     * 
     * @param width Width of the window.
     * @param height Height of the window.
     * @param title Title of the window.
     */
    MainWindow(int width, int height, const char *title);

    /**
     * @brief Updates the UI components with the latest room data.
     * 
     * Dynamically creates buttons and controls based on the current program state.
     */
    void updateButtons();

    /**
     * @brief Overrides the default hide method to save the program state before hiding.
     */
    void hide() override;
};
