#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"

class Thermostat : public SmartDevice {
private:
    int temperature;

public:
    	Thermostat(const std::string&,int);
    	void setTemperature(int);
    	int getTemperature() const;
	void deviceCallback(Fl_Widget*,void*)override;
    	std::string getStatus() const override;
};

#endif // THERMOSTAT_H
