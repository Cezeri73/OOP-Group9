#include "Light.h"
Light::Light(const std::string &deviceName) : SmartDevice(deviceName)
{

    this->type = Type::Light;
}
void Light::notificationCallback(void *data)
{
    Light *light = static_cast<Light *>(data);
    light->statu == Statu::ON ? light->addNotification("Light turned ON.") : light->addNotification("Light turned OFF.");
}
void Light::deviceCallback(Fl_Widget *widget, void *data)
{
    Light *light = static_cast<Light *>(data);
    Fl_Button *button = static_cast<Fl_Button *>(widget);
    Fl_Window *window = static_cast<Fl_Window *>(widget->window());

    if (statu == Statu::OFF)
    {
        light->turnOn();
        button->color(FL_GREEN);
        button->labelcolor(FL_WHITE);
        notificationCallback(data);
    }
    else
    {
        light->turnOff();
        button->color(FL_RED);
        button->labelcolor(FL_WHITE);
        notificationCallback(data);
    }

    window->redraw();
    button->redraw();
}
void Light::turnOn()
{
    statu = Statu::ON;
}

void Light::turnOff()
{
    statu = Statu::OFF;
}