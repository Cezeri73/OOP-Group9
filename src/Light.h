#ifndef LIGHT_H
#define LIGHT_H

#include "SmartDevice.h"
#include <string>

class Light : public SmartDevice {
public:
	Light(const std::string&);
	void turnOn();
	void turnOff();
	void deviceCallback(Fl_Widget*,void*) override;
	static void notificationCallback(void* data);
};

#endif

