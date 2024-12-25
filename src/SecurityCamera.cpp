/**
 * @file SecurityCamera.cpp
 * @brief Implementation of the SecurityCamera class, representing a smart security camera device.
 */

#include "SecurityCamera.h"

/**
 * @brief Constructor for the SecurityCamera class.
 * 
 * Initializes a security camera device with a given name and sets its type to "Security Camera."
 * 
 * @param deviceName The name of the security camera device.
 */
SecurityCamera::SecurityCamera(const std::string &deviceName) : SmartDevice(deviceName)
{
    this->type = Type::SecurityCamera; // Set the device type as Security Camera
}

/**
 * @brief Callback method triggered when the camera's associated button is clicked.
 * 
 * Toggles the security camera between recording and not recording, updates the button appearance, 
 * and adds a notification about the action performed.
 * 
 * @param widget Pointer to the widget triggering the callback.
 * @param data Pointer to user-defined data, expected to be a SecurityCamera object.
 */
void SecurityCamera::deviceCallback(Fl_Widget *widget, void *data)
{
    SecurityCamera *camera = static_cast<SecurityCamera *>(data); // Cast the data pointer to a SecurityCamera object
    Fl_Button *button = static_cast<Fl_Button *>(widget);         // Cast the widget to an Fl_Button object

    if (statu == Statu::OFF) // Check if the camera is currently off
    {
        camera->startRecording();       // Start recording
        button->color(FL_GREEN);        // Change the button color to green
        button->labelcolor(FL_WHITE);   // Set the button label color to white
        addNotification("Security camera started recording."); // Add a notification
    }
    else // If the camera is currently on
    {
        camera->stopRecording();        // Stop recording
        button->color(FL_RED);          // Change the button color to red
        button->labelcolor(FL_WHITE);   // Set the button label color to white
        addNotification("Security camera stopped recording."); // Add a notification
    }
}

/**
 * @brief Starts recording and updates the camera's status to ON.
 */
void SecurityCamera::startRecording()
{
    statu = Statu::ON; // Update the status to ON
}

/**
 * @brief Stops recording and updates the camera's status to OFF.
 */
void SecurityCamera::stopRecording()
{
    statu = Statu::OFF; // Update the status to OFF
}
