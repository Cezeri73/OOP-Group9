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
#include "RemoveRoomScreen.h"
#include <fstream>
class MainWindow : public Fl_Window
{
private:
	static AddRoomScreen addRoomScreen;
	static RemoveRoomScreen removeRoomScreen;
	Fl_Button *addRoomButton;
	Fl_Button *removeRoomButton;
	void saveProgram();
	void loadProgram();

public:
	void updateButtons();
	MainWindow(int, int, const char *);
	void hide() override;
};
