#include "WaterPurifier.h"    
WaterPurifier::WaterPurifier(const std::string& deviceName) 
        : SmartDevice(deviceName), waterQuality(100) {} // Varsayılan kalite %100

    void WaterPurifier::checkQuality() {
        std::srand(std::time(0)); // Rastgele kalite oluştur
        waterQuality = std::rand() % 100;
    }
void WaterPurifier::deviceCallback(Fl_Widget* widget,void* data) {
 WaterPurifier* purifier = static_cast<WaterPurifier*>(data);
    std::srand(std::time(0));
    int quality = std::rand() % 100;
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
