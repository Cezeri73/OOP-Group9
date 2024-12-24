#include "Light.h"

void Light::notificationCallback(void* data) {
    Light* light = static_cast<Light*>(data);
    light->statu == Statu::ON ? light->addNotification("Light turned ON.") : light->addNotification("Light turned OFF.");
}
void Light::deviceCallback(Fl_Widget* widget, void* data) {
    Light* light = static_cast<Light*>(data);
    Fl_Button* button = static_cast<Fl_Button*>(widget);
    Fl_Window* window = static_cast<Fl_Window*>(widget->window());

    if (statu == Statu::OFF){
        light->turnOn();
        button->color(FL_GREEN); 
        button->labelcolor(FL_WHITE); 
        Fl::add_timeout(5.0, notificationCallback,light);
        
    } else {
        light->turnOff();
        button->color(FL_RED); 
        button->labelcolor(FL_WHITE);
        Fl::add_timeout(5.0, notificationCallback,light);
    }
    
    window->redraw(); 
    button->redraw();
}
void Light::turnOn() {
    statu = Statu::ON;
}

void Light::turnOff() {
    statu = Statu::OFF;
}

Light::Light(const std::string& deviceName): SmartDevice(deviceName) {
	brightness = 70;
	}
        
void Light::adjustBrightness(int level) {
        brightness = (level >= 0 && level <= 100) ? level : brightness;
}
std::string Light::getStatus() const{
	return std::string((statu == Statu::ON) ? "ON" : "OFF") + ", Brightness: " + std::to_string(brightness) + "%";
}
