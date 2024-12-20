#include "Light.h"

Light::Light(const std::string& deviceName, Fl_Box* box)
    : SmartDevice(deviceName), box(box) {
    onImage = new Fl_JPEG_Image("light_on.jpg");
    offImage = new Fl_JPEG_Image("light_off.jpg");
    box->image(offImage); // Başlangıç durumu kapalı
}

void Light::toggle() {
    status = !status;
    box->image(status ? onImage : offImage); // Görsel değişimi
    box->redraw(); // Kutuyu yeniden çiz
    notifyObservers("Light " + name + " is now " + (status ? "on" : "off"));
}
