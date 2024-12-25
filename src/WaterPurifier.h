#ifndef WATERPURIFIER_H
#define WATERPURIFIER_H

#include "SmartDevice.h"
#include <string>
#include <cstdlib>
#include <ctime>

class WaterPurifier : public SmartDevice
{
private:
    int waterQuality;

public:
    WaterPurifier(const std::string &deviceName);
    ~WaterPurifier();
    void deviceCallback(Fl_Widget *, void *) override;
    int getWaterQuality() const;
    static void decreaseQualityCallback(void *data);
};

#endif // WATERPURIFIER_H
