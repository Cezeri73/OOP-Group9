#ifndef SECURITYCAMERA_H
#define SECURITYCAMERA_H

#include "SmartDevice.h"
#include <string>

class SecurityCamera : public SmartDevice {
private:
    	bool isRecording; 
public:
	SecurityCamera(const std::string& deviceName);
	void startRecording();
	void deviceCallback(Fl_Widget*,void*) override;
    	void stopRecording();
    	bool isRecordingActive() const;
    	std::string getStatus() const override;
};

#endif // SECURITYCAMERA_H
