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
    	if (curtain->getStatus().find("Closed") != std::string::npos) {
        	curtain->openCurtain();
        	addNotification("Curtain opened.");
    	} else {
        	curtain->closeCurtain();
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


