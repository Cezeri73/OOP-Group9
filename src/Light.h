#ifndef LIGHT_H
#define LIGHT_H

#include "SmartDevice.h"
#include <string>

class Light : public SmartDevice {
private:
    int brightness;

public:
	Light(const std::string&);
	void turnOn();
	void turnOff();
    void adjustBrightness(int level);
	void deviceCallback(Fl_Widget*,void*) override;
	static void notificationCallback(void* data);
    std::string getStatus() const override;
};

#endif // LIGHT_H

