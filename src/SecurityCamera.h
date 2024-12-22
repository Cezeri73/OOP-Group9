#ifndef SECURITYCAMERA_H
#define SECURITYCAMERA_H

#include "SmartDevice.h"
#include <string>

class SecurityCamera : public SmartDevice {
private:
    bool isRecording; // Kameranın kayıt yapıp yapmadığını belirtir

public:
    SecurityCamera(const std::string& deviceName)
        : SmartDevice(deviceName), isRecording(false) {}

    void startRecording() {
        isRecording = true;
        status = "ON"; // Kameranın durumu açık (ON) olarak güncellenir
    }

    void stopRecording() {
        isRecording = false;
        status = "OFF"; // Kameranın durumu kapalı (OFF) olarak güncellenir
    }

    bool isRecordingActive() const {
        return isRecording;
    }

    std::string getStatus() const override {
        std::string recordingStatus = isRecording ? "Yes" : "No";
        return "Status: " + status + ", Recording: " + recordingStatus;
    }
};

#endif // SECURITYCAMERA_H
