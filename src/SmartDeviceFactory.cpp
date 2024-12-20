#include "SmartDeviceFactory.h"
#include "Curtain.h"
#include "Light.h"

SmartDevice* SmartDeviceFactory::createDevice(const std::string& type, const std::string& name) {
    if (type == "Curtain") {
        return new Curtain(name, nullptr); // Box bağlantısı yoksa nullptr kullanılır
    } else if (type == "Light") {
        return new Light(name, nullptr); // Box bağlantısı yoksa nullptr kullanılır
    }
    return nullptr;
}
