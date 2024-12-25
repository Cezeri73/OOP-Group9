#ifndef WATERPURIFIER_H
#define WATERPURIFIER_H

#include "SmartDevice.h"
#include <string>
#include <cstdlib>
#include <ctime>

class WaterPurifier : public SmartDevice {
private:
    	int waterQuality; 
public:
    WaterPurifier(const std::string& deviceName); 
	void checkQuality();
	void deviceCallback(Fl_Widget*,void*) override;
    std::string getStatus() const override;
    bool isQualityPoor() const;
    int getWaterQuality() const;
	static void decreaseQualityCallback(void* data);
};

#endif // WATERPURIFIER_H
