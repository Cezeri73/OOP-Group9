#include "RemoveRoomScreen.h"
#include "Room.h"
RemoveRoomScreen::RemoveRoomScreen()
{
	window = new Fl_Window(300, 200, "Remove Room");
	new Fl_Box(20, 30, 80, 30, "Room Name:");
	roomName = new Fl_Input(110, 30, 150, 30);

	button = new Fl_Button(110, 130, 80, 30, "Enter");
	button->callback(login_cb, this);
	window->end();
}
void RemoveRoomScreen::show()
{
	window->show();
}
bool RemoveRoomScreen::shown()
{
	return window->visible();
}
void RemoveRoomScreen::login_cb(Fl_Widget *widget, void *data)
{
	RemoveRoomScreen *screen = (RemoveRoomScreen *)data;
	screen->handle_login();
}

void RemoveRoomScreen::handle_login()
{
	std::string roomNameStr = roomName->value();
	for(int i = Room::allRooms.size() - 1; i>=0;i--) {
		if(Room::allRooms[i]->roomName == roomNameStr){
			Room::allRooms.erase(Room::allRooms.begin() + i);
			break;		
		}
	}
	window->hide();
}
