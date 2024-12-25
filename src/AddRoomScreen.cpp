#include "AddRoomScreen.h"
#include "Room.h"
AddRoomScreen::AddRoomScreen()
{
	window = new Fl_Window(300, 200, "Add Room");
	new Fl_Box(20, 30, 80, 30, "Room Name:");
	roomName = new Fl_Input(110, 30, 150, 30);

	button = new Fl_Button(110, 130, 80, 30, "Enter");
	button->callback(login_cb, this);
	window->end();
}
void AddRoomScreen::show()
{
	window->show();
}
bool AddRoomScreen::shown()
{
	return window->visible();
}
void AddRoomScreen::login_cb(Fl_Widget *widget, void *data)
{
	AddRoomScreen *screen = (AddRoomScreen *)data;
	screen->handle_login();
}

void AddRoomScreen::handle_login()
{
	std::string roomNameStr = roomName->value();
	Room *roomToAdd = new Room(roomNameStr);
	std::cout << roomNameStr;
	window->hide();
}
