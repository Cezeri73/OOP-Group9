#include "Light.h"
void Light::deviceCallback(Fl_Widget* widget, void* data) {
    Light* light = static_cast<Light*>(data);
    Fl_Button* button = static_cast<Fl_Button*>(widget);
    Fl_Window* window = static_cast<Fl_Window*>(widget->window());

    if (light->getStatus().find("OFF") != std::string::npos) {
        light->turnOn();
        button->color(FL_GREEN); 
        button->labelcolor(FL_WHITE); 
        //addNotification("Light turned ON.");
    } else {
        light->turnOff();
        button->color(FL_RED); 
        button->labelcolor(FL_WHITE); 
        //addNotification("Light turned OFF.");
    }
    window->redraw(); // Pencereyi güncelle
    button->redraw(); // Butonu güncelle
}
void Light::turnOn() {
    status = "ON";
}

void Light::turnOff() {
    status = "OFF";
}

Light::Light(const std::string& deviceName): SmartDevice(deviceName) {
	brightness = 70;
	}
        
void Light::adjustBrightness(int level) {
        brightness = (level >= 0 && level <= 100) ? level : brightness;
}
std::string Light::getStatus() const{
	return std::string((status == "ON") ? "ON" : "OFF") + ", Brightness: " + std::to_string(brightness) + "%";
}
