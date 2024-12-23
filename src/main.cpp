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

#include "SmartHomeSystem.h"
#include "Light.h"
#include "Thermostat.h"
#include "Curtain.h"
#include "SecurityCamera.h"
#include "WaterPurifier.h"
#include "Elevator.h"
#include "LoginScreen.h"
#include "Refrigerator.h"
#include "MainWindow.h"

/*void checkAlerts() {
    Refrigerator* fridge = dynamic_cast<Refrigerator*>(homeSystem.getDevice("Kitchen Refrigerator"));
    WaterPurifier* purifier = dynamic_cast<WaterPurifier*>(homeSystem.getDevice("Kitchen Water Purifier"));
    Elevator* elevator = dynamic_cast<Elevator*>(homeSystem.getDevice("Home Elevator"));

    if (fridge && fridge->getStockLevel() <= 0) {
        addNotification("ALERT: Refrigerator stock is critically low (0 items left)!");
    }

    if (purifier) {
        std::srand(std::time(0));
        int quality = std::rand() % 100;
        if (quality < 50) {
            addNotification("ALERT: Water quality is poor (" + std::to_string(quality) + "%)!");
        }
    }

    if (elevator && std::rand() % 2 == 0) {
        addNotification("ALERT: Elevator requires immediate maintenance!");
    }
}*/

int main() {
	LoginScreen screen;
	MainWindow window(1200,600,"Smart Home Control Panel");
	
	SmartDevice* light = new Light("Living Room Light");
	SmartDevice* thermostat = new Thermostat("Home Thermostat",23);
        SmartDevice* curtain = new Curtain("Bedroom Curtain");
        SmartDevice* camera = new SecurityCamera("Front Door Camera");
        SmartDevice* purifier = new WaterPurifier("Kitchen Water Purifier");
        SmartDevice* elevator = new Elevator("Home Elevator");
        SmartDevice* fridge = new Refrigerator("Kitchen Refrigerator", 8);	

	Room kitchen("Kitchen");
	Room saloon("Saloon");

	kitchen.addDevice(light);
	kitchen.addDevice(thermostat);
	kitchen.addDevice(curtain);
	kitchen.addDevice(camera);
	saloon.addDevice(purifier);
	saloon.addDevice(elevator);
	saloon.addDevice(fridge);

	window.addRoom(kitchen);
	window.addRoom(saloon);

	
	Fl_Text_Display* notificationDisplay = new Fl_Text_Display(350, 80, 500, 300, "Notification Sys");
    	Fl_Text_Buffer* notificationBuffer = SmartDevice::notificationBuffer;
    	notificationDisplay->buffer(notificationBuffer);
    	notificationDisplay->textfont(FL_COURIER);
    	notificationDisplay->textsize(14);
    	notificationDisplay->color(FL_BLACK); // Arka plan siyah
    	notificationDisplay->textcolor(FL_WHITE); // Yazı beyaz
	
	window.show();
	return Fl::run();
}







	
     	// Initialize Smart Home System
 
/*
        // Buttons for Existing Devices
    Fl_Button* lightButton = new Fl_Button(20, 40, 140, 40, "Toggle Light");
    Fl_Button* thermostatButton = new Fl_Button(20, 90, 140, 40, "Adjust Thermostat");
    Fl_Button* curtainButton = new Fl_Button(20, 140, 140, 40, "Toggle Curtain");
    Fl_Button* cameraButton = new Fl_Button(20, 190, 140, 40, "Toggle Camera");

    // Buttons for New Devices
    Fl_Button* waterButton = new Fl_Button(180, 40, 140, 40, "Check Water");
    Fl_Button* elevatorButton = new Fl_Button(180, 90, 140, 40, "Check Elevator");
    Fl_Button* fridgeButton = new Fl_Button(180, 140, 140, 40, "Check Fridge");
    Fl_Button* fridgeStockButton = new Fl_Button(180, 190, 140, 40, "Adjust Stock");

    // Assign Callbacks
    lightButton->callback(toggleLight, light);
    thermostatButton->callback(adjustThermostat, thermostat);
    curtainButton->callback(toggleCurtain, curtain);
    cameraButton->callback(toggleCamera, camera);
    waterButton->callback(checkWaterPurifier, purifier);
    elevatorButton->callback(checkElevator, elevator);
    fridgeButton->callback(checkRefrigerator, fridge);
    fridgeStockButton->callback(adjustRefrigeratorStock, fridge);

    // Notification Display
    Fl_Text_Display* notificationDisplay = new Fl_Text_Display(350, 80, 500, 300, "Notification Sys");
    notificationBuffer = new Fl_Text_Buffer();
    notificationDisplay->buffer(notificationBuffer);
    notificationDisplay->textfont(FL_COURIER);
    notificationDisplay->textsize(14);
    notificationDisplay->color(FL_BLACK); // Arka plan siyah
    notificationDisplay->textcolor(FL_WHITE); // Yazı beyaz

        // Alert System Button
    Fl_Button* alertButton = new Fl_Button(20, 240, 140, 40, "Check Alerts");
    alertButton->callback([](Fl_Widget*, void*) {
        checkAlerts();
    });

    window->end();
    window->show();

    return Fl::run();
}*/
