#pragma once

#include <chrono>
#include <thread>
#include <iostream>
#include "Room.h"
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <vector>
#include <algorithm>
#include "AddRoomScreen.h"
class MainWindow : public Fl_Window{
	private:
		static AddRoomScreen addRoomScreen;	
		Fl_Button* addRoomButton;
	public:
		void updateButtons();
	       	MainWindow(int,int,const char*);
};
