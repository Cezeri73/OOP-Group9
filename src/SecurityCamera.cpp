#include "SecurityCamera.h"

SecurityCamera::SecurityCamera(const std::string& deviceName): SmartDevice(deviceName){
	isRecording = false;
}
void SecurityCamera::startRecording() {
        isRecording = true;
        statu = Statu::ON;
}
void SecurityCamera::deviceCallback(Fl_Widget* widget,void* data){
   	SecurityCamera* camera = static_cast<SecurityCamera*>(data);
	Fl_Button* button = static_cast<Fl_Button*>(widget);
    	if (statu == Statu::OFF) {
        	camera->startRecording();
			button->color(FL_GREEN); 
        	button->labelcolor(FL_WHITE);
        	addNotification("Security camera started recording.");
    	} else {
        	camera->stopRecording();
			button->color(FL_RED); 
        	button->labelcolor(FL_WHITE); 
        	addNotification("Security camera stopped recording.");
    	}
}

void SecurityCamera::stopRecording(){
	statu = Statu::OFF;
}

bool SecurityCamera::isRecordingActive()const{
		return isRecording;
}
std::string SecurityCamera::getStatus() const{
	    if(statu == Statu::ON){
			return "ON";
		}
		else{
			return "OFF";
		}
}	       

