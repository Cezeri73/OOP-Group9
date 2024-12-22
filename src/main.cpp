#include "Room.h"
#include "SmartDevice.h"
#include "MainWindow.h"
#include <FL/Fl.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
int main(){
	SmartDevice a1(1,"light");
	SmartDevice a2(2,"curtains");
	Room a("saloon");
	Room b("kitchen");
	a.addDevice(a1);
	b.addDevice(a1);
	b.addDevice(a2);

	MainWindow window(600,600,"Smart Home System");
	window.addRoom(a);
	window.addRoom(b);
	window.show();
	return Fl::run();
}
