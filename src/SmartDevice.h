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

class SmartDevice {
    
protected:
    enum class Statu {
        ON,
        OFF
    };
    	std::string name;
    	Statu statu;
public:
    enum class Type {
        Refrigerator,
        Thermostat,
        Light,
        WaterPurifier,
        Elevator,
        Curtain,
        SecurityCamera,
    };
    Type type;
	static Fl_Text_Buffer* notificationBuffer; 
    int time;
        //static std::ofstream logFile("notifications.log", std::ios::app);
    SmartDevice(std::string deviceName)
        : name(deviceName), statu(Statu::OFF) {}

    virtual ~SmartDevice() = default;

    const char* getName(){
        	return name.c_str();
    }
    virtual void deviceCallback(Fl_Widget* widget, void* data) = 0;
    virtual std::string getStatus() const = 0;
    void addNotification(const std::string& message) {
    	notificationBuffer->append((message + "\n").c_str());
    	/*if (logFile.is_open()) {
        	logFile << message << std::endl;
    	}*/
	}	 
};

#endif // SMART_DEVICE_H
