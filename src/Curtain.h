#ifndef CURTAIN_H
#define CURTAIN_H

#include "SmartDevice.h"

class Curtain : public SmartDevice {
public:
    Curtain(const std::string& deviceName)
        : SmartDevice(deviceName) {}

    void openCurtain() {
        status = "ON"; // Perde açık
    }

    void closeCurtain() {
        status = "OFF"; // Perde kapalı
    }

    std::string getStatus() const override {
        return "Curtain is " + status;
    }
};

#endif // CURTAIN_H
