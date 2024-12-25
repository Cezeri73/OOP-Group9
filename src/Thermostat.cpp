#include "Thermostat.h"
#include <FL/Fl_Value_Output.H>

Thermostat::Thermostat(const std::string &deviceName, int initialTemp = 22)
    : SmartDevice(deviceName)
{
    this->type = Type::Thermostat;
    temperature = 22;
}
void Thermostat::notificationCallback(void *data)
{
    Thermostat *thermostat = static_cast<Thermostat *>(data);
    thermostat->addNotification("Thermostat temperature set to " + std::to_string(thermostat->getTemperature()) + " °C.");
    thermostat->hour = 0;
}
void Thermostat::setTemperature(int temp)
{
    temperature = temp;
    statu = Statu::ON; // Sıcaklık ayarlandığında durumu ON yap
    Fl::add_timeout(this->hour, notificationCallback, this);
}
int Thermostat::getTemperature() const
{
    return temperature;
}
int degree = 0;
void Thermostat::confirm(Fl_Widget *widget, void *data)
{
    Thermostat *thermostat = static_cast<Thermostat *>(data);
    thermostat->setTemperature(degree);
}

void Thermostat::deviceCallback(Fl_Widget *widget, void *data)
{
    Thermostat *thermostat = static_cast<Thermostat *>(data);
    Fl_Window *thermoWindow = new Fl_Window(600, 300, "Thermostat");
    thermoWindow->color(FL_GRAY);

    Fl_Slider *thermoSlider = new Fl_Slider(150, 120, 300, 30);
    thermoSlider->type(FL_HORIZONTAL);
    thermoSlider->minimum(0);
    thermoSlider->maximum(100);
    thermoSlider->value(thermostat->getTemperature());
    thermoSlider->step(1);

    Fl_Value_Output *valueOutput = new Fl_Value_Output(250, 160, 100, 30);
    valueOutput->label("Temperature:");
    valueOutput->textsize(16);
    valueOutput->align(FL_ALIGN_CENTER);
    valueOutput->value(thermoSlider->value());
    thermoSlider->user_data(thermostat);
    thermoSlider->callback([](Fl_Widget *widget, void *data)
                           {
                               Fl_Slider *slider = static_cast<Fl_Slider *>(widget);
                               Fl_Value_Output *valueOutput = static_cast<Fl_Value_Output *>(data);
                               valueOutput->value(slider->value());
                               degree = slider->value(); },
                           valueOutput);
    Fl_Button *confirmButton = new Fl_Button(250, 200, 100, 40, "Confirm");
    confirmButton->callback(confirm, thermostat);
    thermoWindow->end();
    thermoWindow->show();
};
