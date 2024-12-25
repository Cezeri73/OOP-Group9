#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Input.H>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "Light.h"
#include "Thermostat.h"
#include "Curtain.h"
#include "SecurityCamera.h"
#include "WaterPurifier.h"
#include "Elevator.h"
#include "LoginScreen.h"
#include "Refrigerator.h"
#include "MainWindow.h"
#include "AddDeviceScreen.h"

int main()
{
    LoginScreen screen;
    MainWindow window(1200, 600, "Smart Home Control Panel");

    SmartDevice *light = new Light("Light");
    SmartDevice *thermostat = new Thermostat("Thermostat", 23);
    SmartDevice *curtain = new Curtain("Curtain");
    SmartDevice *camera = new SecurityCamera("Camera");
    SmartDevice *purifier = new WaterPurifier("Purifier");
    SmartDevice *elevator = new Elevator("Elevator");
    SmartDevice *fridge = new Refrigerator("Refrigerator", 8);

    Fl_Text_Display *notificationDisplay = new Fl_Text_Display(350, 80, 500, 300, "Notification Sys");
    Fl_Text_Buffer *notificationBuffer = SmartDevice::notificationBuffer;
    notificationDisplay->buffer(notificationBuffer);
    notificationDisplay->textfont(FL_COURIER);
    notificationDisplay->textsize(14);
    notificationDisplay->color(FL_BLACK);
    notificationDisplay->textcolor(FL_WHITE);
    window.show();

    return Fl::run();
}