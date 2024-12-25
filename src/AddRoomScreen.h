#pragma once
#include <FL/fl_ask.H> 
#include <string>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
class AddRoomScreen
{
public:
	AddRoomScreen();
	void show();
	bool shown();

private:
	Fl_Window *window;
	Fl_Input *roomName;
	Fl_Button *button;
	static void login_cb(Fl_Widget *, void *);
	void handle_login();
};
