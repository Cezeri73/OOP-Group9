#include "Curtain.h"

Curtain::Curtain(const std::string& deviceName)
        : SmartDevice(deviceName) {}

void Curtain::openCurtain(){
       statu = Statu::ON;
}
void Curtain::closeCurtain() {
        statu = Statu::OFF; 
}
void Curtain::deviceCallback(Fl_Widget* widget,void* data) {
	Curtain* curtain = static_cast<Curtain*>(data);
	Fl_Button* button = static_cast<Fl_Button*>(widget);
    	if (statu==Statu::OFF) {
        	curtain->openCurtain();
			button->color(FL_GREEN); 
        	button->labelcolor(FL_WHITE);
        	addNotification("Curtain opened.");
    	} else {
        	curtain->closeCurtain();
			button->color(FL_RED); 
        	button->labelcolor(FL_WHITE); 
       	 	addNotification("Curtain closed.");
    	}
}	
std::string Curtain::getStatus() const{
      if(statu==Statu::ON){
		return "Open";
	  }
	  else{
		return "Closed";
	  }
}       


