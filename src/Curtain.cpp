#include "Curtain.h"

Curtain::Curtain(const std::string& deviceName)
        : SmartDevice(deviceName) {}

void Curtain::openCurtain() {
        status = "ON"; // Perde açık
}
void Curtain::closeCurtain() {
        status = "OFF"; // Perde kapalı
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
       return status;
}       


