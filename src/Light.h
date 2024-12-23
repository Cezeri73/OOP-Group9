#ifndef LIGHT_H
#define LIGHT_H

#include "SmartDevice.h"
#include <string>

class Light : public SmartDevice {
private:
    int brightness;

public:
	void turnOn();
	void turnOff();
	Light(const std::string&);
        void adjustBrightness(int level);
	void deviceCallback(Fl_Widget*,void*) override;
    	std::string getStatus() const override;
};

#endif // LIGHT_H

