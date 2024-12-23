#include "MainWindow.h"
AddRoomScreen MainWindow::addRoomScreen;
MainWindow::MainWindow(int w,int h,const char* name) : Fl_Window(w,h,name){
	addRoomButton = new Fl_Button(900,20,200,30,"Add Room");
	addRoomButton->callback([](Fl_Widget* widget,void* data){
		MainWindow* mw = static_cast<MainWindow*>(data);
		addRoomScreen.show();
		while(addRoomScreen.shown()){
			Fl::wait();
		}
		mw->updateButtons();
	},this);
	this->draw();
};

void MainWindow::updateButtons(){
	this->hide();
	this->begin();	
	std::vector<Room*> rooms = Room::allRooms;
	
	Fl_Text_Display* notificationDisplay = new Fl_Text_Display(350, 80, 500, 300, "Notification Sys");
    	Fl_Text_Buffer* notificationBuffer = SmartDevice::notificationBuffer;
    	notificationDisplay->buffer(notificationBuffer);
    	notificationDisplay->textfont(FL_COURIER);
    	notificationDisplay->textsize(14);
    	notificationDisplay->color(FL_BLACK); // Arka plan siyah
    	notificationDisplay->textcolor(FL_WHITE); 
	
	
	int yPosition = 20;
        for (size_t i = 0; i < rooms.size(); i++) {
            Fl_Button* roomButton = new Fl_Button(100, yPosition, 200, 30, rooms[i]->roomName.c_str());
	    std::cout<<rooms[i]->roomName;
            roomButton->callback([](Fl_Widget* widget,void* data){
			    Room* r = static_cast<Room*>(data);
			    r->showRoom();
			    },
			    rooms[i]);
            yPosition += 40; 
        }
	this->end();
	this->show();
}
