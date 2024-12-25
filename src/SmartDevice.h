#ifndef SMART_DEVICE_H
#define SMART_DEVICE_H

#include <string>
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Text_Buffer.H>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class SmartDevice
{

protected:
    enum class Statu
    {
        ON,
        OFF
    };
    std::string name;
    Statu statu;

public:
    enum class Type
    {
        Refrigerator,
        Thermostat,
        Light,
        WaterPurifier,
        Elevator,
        Curtain,
        SecurityCamera,
    };
    Type type;
    static Fl_Text_Buffer *notificationBuffer;
    int hour;
    SmartDevice(std::string deviceName)
        : name(deviceName), statu(Statu::OFF) {}

    virtual ~SmartDevice() = default;

    const char *getName();
    virtual void deviceCallback(Fl_Widget *widget, void *data) = 0;
    void addNotification(const std::string &message);
    json toJson() const;
    static SmartDevice *fromJson(const json &j);
};

#endif // SMART_DEVICE_H
