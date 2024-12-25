/**
 * @file Curtain.cpp
 * @brief Implementation of the Curtain class, representing a smart curtain device.
 */

#include "Curtain.h"

/**
 * @brief Constructor for the Curtain class.
 * 
 * Initializes the Curtain object with a device name and sets the device type to "Curtain."
 * 
 * @param deviceName The name of the curtain device.
 */
Curtain::Curtain(const std::string &deviceName)
	: SmartDevice(deviceName) // Initialize base class with device name
{
	this->type = Type::Curtain; // Set the device type to "Curtain"
}

/**
 * @brief Opens the curtain by updating its status to ON.
 */
void Curtain::openCurtain()
{
	statu = Statu::ON; // Update the status to ON (open)
}

/**
 * @brief Closes the curtain by updating its status to OFF.
 */
void Curtain::closeCurtain()
{
	statu = Statu::OFF; // Update the status to OFF (closed)
}

/**
 * @brief Callback function for the curtain button.
 * 
 * Toggles the curtain's status between open and closed. Updates the button appearance
 * and adds a corresponding notification for the action performed.
 * 
 * @param widget Pointer to the widget triggering the callback.
 * @param data Pointer to user-defined data, expected to be a Curtain object.
 */
void Curtain::deviceCallback(Fl_Widget *widget, void *data)
{
	// Cast the `data` pointer to a `Curtain` object
	Curtain *curtain = static_cast<Curtain *>(data);

	// Cast the widget to an `Fl_Button` for UI updates
	Fl_Button *button = static_cast<Fl_Button *>(widget);

	// Check the current status of the curtain
	if (statu == Statu::OFF) // If the curtain is closed
	{
		curtain->openCurtain(); // Open the curtain
		button->color(FL_GREEN); // Update button color to green
		button->labelcolor(FL_WHITE); // Update button label color to white
		addNotification("Curtain opened."); // Add a notification for the action
	}
	else // If the curtain is open
	{
		curtain->closeCurtain(); // Close the curtain
		button->color(FL_RED); // Update button color to red
		button->labelcolor(FL_WHITE); // Update button label color to white
		addNotification("Curtain closed."); // Add a notification for the action
	}
}
