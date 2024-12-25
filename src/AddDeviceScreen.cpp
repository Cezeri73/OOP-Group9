#include "AddDeviceScreen.h"
AddDeviceScreen::AddDeviceScreen()
{
	window = new Fl_Window(300, 200, "Device Add Screen");
	choice = new Fl_Choice(100, 50, 100, 30);
	choice->add("Refrigerator");
	choice->add("Thermostat");
	choice->add("Light");
	choice->add("WaterPurifier");
	choice->add("Elevator");
	choice->add("Curtain");
	choice->add("Camera");
	button = new Fl_Button(110, 130, 80, 30, "Enter");
	button->callback(login_cb, this);
	window->end();
}
void AddDeviceScreen::show()
{
	window->show();
}
bool AddDeviceScreen::shown()
{
	return window->visible();
}
void AddDeviceScreen::login_cb(Fl_Widget *widget, void *data)
{
	Fl_Window *parent_window = widget->window();
	parent_window->hide();
}

void AddDeviceScreen::handle_login()
{
}
