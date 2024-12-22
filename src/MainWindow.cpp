#include "MainWindow.h"

MainWindow::MainWindow(int w,int h,const char* name) : Fl_Window(w,h,name){};

void MainWindow::addRoom(Room& room){
	rooms.push_back(room);
	updateButtons();
}
void MainWindow::updateButtons(){
	this->clear();
	
	int yPosition = 20;
        for (size_t i = 0; i < rooms.size(); ++i) {
            Fl_Button* roomButton = new Fl_Button(100, yPosition, 200, 30, rooms[i].roomName.c_str());
            roomButton->callback([](Fl_Widget* widget,void* data){
			    Room* r = static_cast<Room*>(data);
			    r->showRoom();
			    },
			    &rooms[i]);
            yPosition += 40; 
        }
	this->redraw();
}

