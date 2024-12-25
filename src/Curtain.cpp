#include "Curtain.h"

// Constructor to initialize the Curtain object
Curtain::Curtain(const std::string &deviceName)
	: SmartDevice(deviceName) // Initialize base class with device name
{
	this->type = Type::Curtain; // Set the device type to "Curtain"
}

// Method to open the curtain
void Curtain::openCurtain()
{
	statu = Statu::ON; // Update the status to ON (open)
}

// Method to close the curtain
void Curtain::closeCurtain()
{
	statu = Statu::OFF; // Update the status to OFF (closed)
}

// Callback function for the curtain button
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
