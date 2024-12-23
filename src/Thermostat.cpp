#include "Thermostat.h"

Thermostat::Thermostat(const std::string& deviceName, int initialTemp = 22)
        : SmartDevice(deviceName){
		temperature = 22;
	}
void Thermostat::setTemperature(int temp) {
       	temperature = temp;
        statu= Statu::ON; // Sıcaklık ayarlandığında durumu ON yap
    }
int Thermostat::getTemperature() const {
        return temperature;
}
void Thermostat::deviceCallback(Fl_Widget* widget ,void* data ){
	Thermostat* thermostat = static_cast<Thermostat*>(data);
    	thermostat->setTemperature(thermostat->getTemperature() + 1);
    //addNotification("Thermostat temperature adjusted to " + std::to_string(thermostat->getTemperature()) + "°C.");
};
std::string Thermostat::getStatus() const{
        if(statu==Statu::ON){
            return "Thermostat is on, Temperature: " + std::to_string(temperature) + "°C";
        }
        return "Thermostat is off, Temperature: " + std::to_string(temperature) + "°C";

}
