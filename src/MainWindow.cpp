#include "MainWindow.h"
AddRoomScreen MainWindow::addRoomScreen;
RemoveRoomScreen MainWindow::removeRoomScreen;
MainWindow::MainWindow(int w, int h, const char *name) : Fl_Window(w, h, name)
{
	loadProgram();
};
void MainWindow::saveProgram()
{
	json allRoomsJson = json::array();
	for (const auto &room : Room::allRooms)
	{
		allRoomsJson.push_back(room->toJson());
	}

	std::ofstream outFile("saveFile");
	if (outFile.is_open())
	{
		outFile << allRoomsJson.dump(4);
		outFile.close();
	}
	else
	{
		std::cerr << "Error opening file for writing!" << std::endl;
	}
}
void MainWindow::loadProgram()
{

	std::ifstream inFile("saveFile");
	if (inFile.is_open())
	{
		json allRoomsJson;
		inFile >> allRoomsJson;

		for (const auto &roomJson : allRoomsJson)
		{
			Room::fromJson(roomJson);
		}
	}
	else
	{
		std::cerr << "Error opening file for reading!" << std::endl;
	}
	updateButtons();
}

void MainWindow::updateButtons()
{
	Fl_Window::hide();
	this->clear();
	this->begin();
	std::vector<Room *> rooms = Room::allRooms;

	addRoomButton = new Fl_Button(900, 20, 200, 30, "Add Room");
	addRoomButton->callback([](Fl_Widget *widget, void *data)
							{
		MainWindow* mw = static_cast<MainWindow*>(data);
		addRoomScreen.show();
		while(addRoomScreen.shown()){
			Fl::wait();
		}
		mw->updateButtons(); }, this);

	removeRoomButton = new Fl_Button(900, 60, 200,30 ,"Remove Room");
	removeRoomButton->callback([](Fl_Widget *widget, void *data)
							{
		MainWindow* mw = static_cast<MainWindow*>(data);
		removeRoomScreen.show();
		while(removeRoomScreen.shown()){
			Fl::wait();
		}
		mw->updateButtons(); }, this);
	
	
	Fl_Text_Display *notificationDisplay = new Fl_Text_Display(350, 80, 500, 300, "Notification Sys");
	Fl_Text_Buffer *notificationBuffer = SmartDevice::notificationBuffer;
	notificationDisplay->buffer(notificationBuffer);
	notificationDisplay->textfont(FL_COURIER);
	notificationDisplay->textsize(14);
	notificationDisplay->color(FL_BLACK);
	notificationDisplay->textcolor(FL_WHITE);

	int yPosition = 20;
	for (size_t i = 0; i < rooms.size(); i++)
	{
		Fl_Button *roomButton = new Fl_Button(100, yPosition, 200, 30, rooms[i]->roomName.c_str());
		roomButton->callback([](Fl_Widget *widget, void *data)
							 {
			    Room* r = static_cast<Room*>(data);
			    r->showRoom(); },
							 rooms[i]);
		yPosition += 40;
	}
	this->end();
	this->show();
}

void MainWindow::hide()
{
	this->saveProgram();
	Fl_Window::hide();
}
