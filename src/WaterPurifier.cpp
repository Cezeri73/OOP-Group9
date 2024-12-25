#include "WaterPurifier.h"
WaterPurifier::WaterPurifier(const std::string &deviceName)
    : SmartDevice(deviceName), waterQuality(100)
{
    this->type = Type::WaterPurifier;
    Fl::repeat_timeout(10.0, WaterPurifier::decreaseQualityCallback, this);
}
WaterPurifier::~WaterPurifier()
{
    delete this;
}

void WaterPurifier::decreaseQualityCallback(void *data)
{
    WaterPurifier *purifier = static_cast<WaterPurifier *>(data);
    int decrease = 1;
    purifier->waterQuality -= decrease;
    if (purifier->getWaterQuality() > 0)
    {
        Fl::repeat_timeout(10.0, decreaseQualityCallback, data);
    }
}
void WaterPurifier::deviceCallback(Fl_Widget *widget, void *data)
{
    WaterPurifier *purifier = static_cast<WaterPurifier *>(data);
    int quality = purifier->waterQuality;
    if (quality < 50)
    {
        addNotification("Warning: Water quality is poor (" + std::to_string(getWaterQuality()) + "%).");
    }
    else
    {
        addNotification("Water quality is good (" + std::to_string(getWaterQuality()) + "%).");
    }
};

int WaterPurifier::getWaterQuality() const
{
    return waterQuality;
}
