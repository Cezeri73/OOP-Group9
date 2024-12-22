#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_JPEG_Image.H>
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

// Globals
SmartHomeSystem homeSystem;
Fl_Text_Buffer* notificationBuffer;
std::ofstream logFile("notifications.log", std::ios::app);

// Utility Function for Notifications
void addNotification(const std::string& message) {
    notificationBuffer->append((message + "\n").c_str());
    homeSystem.notifyAll(message);
    if (logFile.is_open()) {
        logFile << message << std::endl;
    }
}

// Alert System
void checkAlerts() {
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
}

// Callbacks for Existing Devices
void toggleLight(Fl_Widget* widget, void* data) {
    Light* light = static_cast<Light*>(data);
    Fl_Button* button = static_cast<Fl_Button*>(widget);
    Fl_Window* window = static_cast<Fl_Window*>(widget->window());

    if (light->getStatus().find("OFF") != std::string::npos) {
        light->turnOn();
        window->color(FL_WHITE); // Arka plan rengini parlak yap
        button->color(FL_GREEN); // Buton arka planını yeşil yap
        button->labelcolor(FL_WHITE); // Buton yazı rengini beyaz yap
        addNotification("Light turned ON.");
    } else {
        light->turnOff();
        window->color(FL_GRAY); // Arka plan rengini koyu yap
        button->color(FL_RED); // Buton arka planını kırmızı yap
        button->labelcolor(FL_WHITE); // Buton yazı rengini beyaz yap
        addNotification("Light turned OFF.");
    }
    window->redraw(); // Pencereyi güncelle
    button->redraw(); // Butonu güncelle
}

void adjustThermostat(Fl_Widget*, void* data) {
    Thermostat* thermostat = static_cast<Thermostat*>(data);
    thermostat->setTemperature(thermostat->getTemperature() + 1);
    addNotification("Thermostat temperature adjusted to " + std::to_string(thermostat->getTemperature()) + "°C.");
}

void toggleCurtain(Fl_Widget*, void* data) {
    Curtain* curtain = static_cast<Curtain*>(data);
    if (curtain->getStatus().find("Closed") != std::string::npos) {
        curtain->openCurtain();
        addNotification("Curtain opened.");
    } else {
        curtain->closeCurtain();
        addNotification("Curtain closed.");
    }
}

void toggleCamera(Fl_Widget*, void* data) {
    SecurityCamera* camera = static_cast<SecurityCamera*>(data);
    if (camera->getStatus().find("No") != std::string::npos) {
        camera->startRecording();
        addNotification("Security camera started recording.");
    } else {
        camera->stopRecording();
        addNotification("Security camera stopped recording.");
    }
}

// Callbacks for New Devices
void checkWaterPurifier(Fl_Widget*, void* data) {
    WaterPurifier* purifier = static_cast<WaterPurifier*>(data);
    std::srand(std::time(0));
    int quality = std::rand() % 100;
    if (quality < 50) {
        addNotification("Warning: Water quality is poor (" + std::to_string(quality) + "%).");
    } else {
        addNotification("Water quality is good (" + std::to_string(quality) + "%).");
    }
}

void checkElevator(Fl_Widget*, void* data) {
    Elevator* elevator = static_cast<Elevator*>(data);
    if (std::rand() % 2 == 0) {
        addNotification("Elevator maintenance required!");
    } else {
        addNotification("Elevator is functioning well.");
    }
}

void checkRefrigerator(Fl_Widget*, void* data) {
    Refrigerator* fridge = static_cast<Refrigerator*>(data);
    if (fridge->getStockLevel() < 5) {
        addNotification("Warning: Refrigerator stock is low (" + std::to_string(fridge->getStockLevel()) + ").");
    } else {
        addNotification("Refrigerator stock is sufficient (" + std::to_string(fridge->getStockLevel()) + ").");
    }
}

void adjustRefrigeratorStock(Fl_Widget*, void* data) {
    Refrigerator* fridge = static_cast<Refrigerator*>(data);
    fridge->adjustStock(-1);
    addNotification("Refrigerator stock adjusted. Current stock: " + std::to_string(fridge->getStockLevel()));
}

int main() {
	LoginScreen screen;
	MainWindow window(1200,600,"Smart Home Control Panel");
	
	std::shared_ptr<SmartDevice> light = std::make_shared<Light>("Living Room Light");
	std::shared_ptr<SmartDevice> thermostat = std::make_shared<Thermostat>("Home Thermostat");
        std::shared_ptr<SmartDevice> curtain = std::make_shared<Curtain>("Bedroom Curtain");
        std::shared_ptr<SmartDevice> camera = std::make_shared<SecurityCamera>("Front Door Camera");
        std::shared_ptr<SmartDevice> purifier = std::make_shared<WaterPurifier>("Kitchen Water Purifier");
        std::shared_ptr<SmartDevice> elevator = std::make_shared<Elevator>("Home Elevator");
        std::shared_ptr<SmartDevice> fridge = std::make_shared<Refrigerator>("Kitchen Refrigerator", 8);

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
    notificationBuffer = new Fl_Text_Buffer();
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
    homeSystem.addDevice(light);
    homeSystem.addDevice(thermostat);
    homeSystem.addDevice(curtain);
    homeSystem.addDevice(camera);
    homeSystem.addDevice(purifier);
    homeSystem.addDevice(elevator);
    homeSystem.addDevice(fridge);

    // FLTK Window
    Fl_Window* window = new Fl_Window(1200, 600, "Smart Home Control Panel");
    window->color(FL_GRAY); // Başlangıç rengi gri

    // Welcome Message
    Fl_Box* welcomeBox = new Fl_Box(300, 10, 600, 40, "Welcome To Our Smart System");
    welcomeBox->box(FL_NO_BOX);
    welcomeBox->labelfont(FL_BOLD + FL_ITALIC);
    welcomeBox->labelsize(24);
    welcomeBox->labelcolor(FL_BLUE);

    // Background Image
    Fl_JPEG_Image* bgImage = new Fl_JPEG_Image("background.jpg");
    Fl_Box* background = new Fl_Box(0, 0, 1000, 600);
    background->image(bgImage);

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

    // User Account Section
    Fl_Box* userBox = new Fl_Box(950, 40, 200, 250, "User Account");
    userBox->box(FL_UP_BOX);
    userBox->labelfont(FL_BOLD);
    userBox->labelsize(14);
    userBox->color(FL_LIGHT3);

    Fl_Input* userNameInput = new Fl_Input(950, 80, 180, 25, "Home Name:");
    Fl_Input* homeNameInput = new Fl_Input(950, 130, 180, 25, "Password:");
    Fl_Button* loginButton = new Fl_Button(950, 180, 180, 30, "Log In");

    // Adjust Button Colors and Fonts
    loginButton->color(FL_BLUE);
    loginButton->labelcolor(FL_WHITE);
    loginButton->labelfont(FL_BOLD);
    loginButton->labelsize(14);

    // Alert System Button
    Fl_Button* alertButton = new Fl_Button(20, 240, 140, 40, "Check Alerts");
    alertButton->callback([](Fl_Widget*, void*) {
        checkAlerts();
    });

    window->end();
    window->show();

    return Fl::run();
}*/
