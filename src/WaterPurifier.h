#ifndef WATERPURIFIER_H
#define WATERPURIFIER_H

#include "SmartDevice.h"
#include <string>
#include <cstdlib>
#include <ctime>

class WaterPurifier : public SmartDevice {
private:
    int waterQuality; // Su kalitesi yüzdesi

public:
    WaterPurifier(const std::string& deviceName) 
        : SmartDevice(deviceName), waterQuality(100) {} // Varsayılan kalite %100

    void checkQuality() {
        std::srand(std::time(0)); // Rastgele kalite oluştur
        waterQuality = std::rand() % 100;
    }

    std::string getStatus() const override {
        return "Water Quality: " + std::to_string(waterQuality) + "%";
    }

    bool isQualityPoor() const {
        return waterQuality < 50; // Kalite %50'den düşükse "kötü" olarak değerlendir
    }

    int getWaterQuality() const {
        return waterQuality;
    }
};

#endif // WATERPURIFIER_H
