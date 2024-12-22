#pragma once

#include <iostream>
#include "Room.h"
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <vector>
#include <algorithm>
class MainWindow : public Fl_Window{
	private:
		std::vector<Room> rooms;
		void updateButtons();
	public:
		MainWindow(int,int,const char*);
		void addRoom(Room&);
};
