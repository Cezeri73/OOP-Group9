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
    	std::string name;
    	std::string status; 
public:
	static Fl_Text_Buffer* notificationBuffer; 
        //static std::ofstream logFile("notifications.log", std::ios::app);
public:
    SmartDevice(std::string deviceName)
        : name(deviceName), status("OFF") {}

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
