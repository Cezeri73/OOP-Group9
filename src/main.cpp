/**
 * @file main.cpp
 * @brief Entry point for the Smart Home Control Panel application.
 * 
 * This program initializes the login screen, main window, and various smart devices,
 * and provides a user interface to interact with the smart home system.
 */

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Input.H>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "Light.h"
#include "Thermostat.h"
#include "Curtain.h"
#include "SecurityCamera.h"
#include "WaterPurifier.h"
#include "Elevator.h"
#include "LoginScreen.h"
#include "Refrigerator.h"
#include "MainWindow.h"
#include "AddDeviceScreen.h"

/**
 * @brief Main function for the Smart Home Control Panel application.
 * 
 * This function initializes the login screen, verifies user authentication, creates instances
 * of various smart devices, and starts the FLTK event loop to handle user interactions.
 * 
 * @return int Exit code of the program (0 for successful execution).
 */
int main()
{
    // Create an instance of LoginScreen
    LoginScreen screen;

    // Create an instance of MainWindow with specific dimensions and title
    MainWindow window(1200, 600, "Smart Home Control Panel");

    // Check if the user is authorized (if not, exit the program)
    if (!screen.authorized)
    {
        return 0; // Exit the program if not authorized
    }

    // Create instances of different SmartDevices
    SmartDevice *light = new Light("Light");
    SmartDevice *thermostat = new Thermostat("Thermostat", 23);
    SmartDevice *curtain = new Curtain("Curtain");
    SmartDevice *camera = new SecurityCamera("Camera");
    SmartDevice *purifier = new WaterPurifier("Purifier");
    SmartDevice *elevator = new Elevator("Elevator");
    SmartDevice *fridge = new Refrigerator("Refrigerator", 8);

    // Create a Fl_Text_Display to show notifications
    Fl_Text_Display *notificationDisplay = new Fl_Text_Display(350, 80, 500, 300, "Notification Sys");

    // Set the notification buffer from the SmartDevice class to show messages
    Fl_Text_Buffer *notificationBuffer = SmartDevice::notificationBuffer;

    // Associate the notification buffer with the text display widget
    notificationDisplay->buffer(notificationBuffer);

    // Set the font and size of the displayed text
    notificationDisplay->textfont(FL_COURIER);
    notificationDisplay->textsize(14);

    // Set the text and background colors of the notification display
    notificationDisplay->color(FL_BLACK); // Background color
    notificationDisplay->textcolor(FL_WHITE); // Text color

    // Show the main window
    window.show();

    // Start the FLTK event loop (necessary to handle UI events)
    return Fl::run(); // Run the FLTK event loop
}
