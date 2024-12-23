#include "Elevator.h"
Elevator::Elevator(const std::string& deviceName)
        : SmartDevice(deviceName), maintenanceRequired(false) {}

    void Elevator::checkMaintenance() {
        // Rastgele bir değer ile bakım durumunu kontrol et
        maintenanceRequired = (std::rand() % 2 == 0);
    }
void Elevator::deviceCallback(Fl_Widget* widget,void* data) {
    Elevator* elevator = static_cast<Elevator*>(data);
    if (std::rand() % 2 == 0) {
        addNotification("Elevator maintenance required!");
    } else {
        addNotification("Elevator is functioning well.");
    }
};
    bool Elevator::isMaintenanceRequired() const {
        return maintenanceRequired;
    }

    std::string Elevator::getStatus() const {
        return "Elevator Status: " + std::string(maintenanceRequired ? "Maintenance Required" : "Operational");
    }

