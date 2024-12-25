#ifndef SECURITYCAMERA_H
#define SECURITYCAMERA_H

#include "SmartDevice.h"
#include <string>

class SecurityCamera : public SmartDevice
{
public:
	SecurityCamera(const std::string &deviceName);
	void startRecording();
	void deviceCallback(Fl_Widget *, void *) override;
	void stopRecording();
};

#endif // SECURITYCAMERA_H
