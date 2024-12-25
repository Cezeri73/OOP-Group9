#include "SecurityCamera.h"

// Constructor to initialize the security camera and set its type
SecurityCamera::SecurityCamera(const std::string &deviceName) : SmartDevice(deviceName)
{
    this->type = Type::SecurityCamera; // Set the device type as Security Camera
}

// Callback method triggered when the camera's associated button is clicked
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

// Method to start recording and change the camera's status to ON
void SecurityCamera::startRecording()
{
    statu = Statu::ON; // Update the status to ON
}

// Method to stop recording and change the camera's status to OFF
void SecurityCamera::stopRecording()
{
    statu = Statu::OFF; // Update the status to OFF
}
