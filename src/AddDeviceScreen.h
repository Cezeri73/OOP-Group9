#pragma once
#include <FL/fl_ask.H> 
#include <string>
#include <FL/Fl_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
class AddDeviceScreen
{
public:
	AddDeviceScreen();
	void show();
	bool shown();
	Fl_Choice *choice;

private:
	Fl_Window *window;
	Fl_Button *button;

	static void login_cb(Fl_Widget *, void *);
	void handle_login();
};
