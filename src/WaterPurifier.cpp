#include "WaterPurifier.h"    
WaterPurifier::WaterPurifier(const std::string& deviceName) 
        : SmartDevice(deviceName), waterQuality(100) {
        this->type=Type::WaterPurifier;
        Fl::repeat_timeout(10.0, WaterPurifier::decreaseQualityCallback, this);
        } 

    void WaterPurifier::checkQuality() {
        std::srand(std::time(0)); // Rastgele kalite oluştur
        waterQuality = std::rand() % 100;
    }
void WaterPurifier::decreaseQualityCallback(void* data) {
    WaterPurifier* purifier = static_cast<WaterPurifier*>(data);
    int decrease = 1;
    purifier->waterQuality-=decrease;
    if (purifier->getWaterQuality() > 0) {
        Fl::repeat_timeout(10.0, decreaseQualityCallback, data);
    }
}
void WaterPurifier::deviceCallback(Fl_Widget* widget,void* data) {
    WaterPurifier* purifier = static_cast<WaterPurifier*>(data);
    int quality = purifier->waterQuality;
    if (quality < 50) {
        addNotification("Warning: Water quality is poor (" + std::to_string(quality) + "%).");
    } else {
        addNotification("Water quality is good (" + std::to_string(quality) + "%).");
    }


};
    std::string WaterPurifier::getStatus() const {
        return "Water Quality: " + std::to_string(waterQuality) + "%";
    }

    bool WaterPurifier::isQualityPoor() const {
        return waterQuality < 50; // Kalite %50'den düşükse "kötü" olarak değerlendir
    }

    int WaterPurifier::getWaterQuality() const {
        return waterQuality;
    }
