/**
 * @file SecurityCamera.h
 * @brief Header file for the SecurityCamera class, representing a smart security camera device.
 */

#ifndef SECURITYCAMERA_H
#define SECURITYCAMERA_H

#include "SmartDevice.h"
#include <string>

/**
 * @class SecurityCamera
 * @brief Represents a smart security camera in the smart home system.
 * 
 * The SecurityCamera class provides functionality to toggle recording on and off 
 * and includes a callback method for user interaction through the GUI.
 */
class SecurityCamera : public SmartDevice
{
public:
    /**
     * @brief Constructor for the SecurityCamera class.
     * 
     * Initializes a security camera device with a given name and sets its type.
     * 
     * @param deviceName The name of the security camera device.
     */
    SecurityCamera(const std::string &deviceName);

    /**
     * @brief Starts recording and updates the camera's status to ON.
     */
    void startRecording();

    /**
     * @brief Stops recording and updates the camera's status to OFF.
     */
    void stopRecording();

    /**
     * @brief Callback method triggered when the camera's associated button is clicked.
     * 
     * Toggles the security camera between recording and not recording, updates the button appearance,
     * and generates a notification about the action performed.
     * 
     * @param widget Pointer to the widget triggering the callback.
     * @param data Pointer to user-defined data, expected to be a SecurityCamera object.
     */
    void deviceCallback(Fl_Widget *, void *) override;

};

#endif // SECURITYCAMERA_H
