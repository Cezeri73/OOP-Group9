#include "SecurityCamera.h"

SecurityCamera::SecurityCamera(const std::string& deviceName): SmartDevice(deviceName){
	isRecording = false;
}
void SecurityCamera::startRecording() {
        isRecording = true;
        status = "ON";
}
void SecurityCamera::deviceCallback(Fl_Widget* widget,void* data){
   	SecurityCamera* camera = static_cast<SecurityCamera*>(data);
    	if (camera->getStatus().find("No") != std::string::npos) {
        	camera->startRecording();
        	addNotification("Security camera started recording.");
    	} else {
        	camera->stopRecording();
        	addNotification("Security camera stopped recording.");
    	}
}

void SecurityCamera::stopRecording(){
	status = "OFF";
}
    	bool SecurityCamera::isRecordingActive()const{
		return isRecording;
	}
    	std::string SecurityCamera::getStatus() const{
	       return status;
	}	       

