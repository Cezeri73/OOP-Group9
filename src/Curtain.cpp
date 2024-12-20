#include "Curtain.h"

Curtain::Curtain(const std::string& deviceName, Fl_Box* box)
    : SmartDevice(deviceName), box(box) {
    openImage = new Fl_JPEG_Image("curtain_open.jpg");
    closedImage = new Fl_JPEG_Image("curtain_closed.jpg");
    box->image(closedImage); // Başlangıç durumu kapalı
}

void Curtain::toggle() {
    status = !status;
    box->image(status ? openImage : closedImage); // Görsel değişimi
    box->redraw(); // Kutuyu yeniden çiz
    notifyObservers("Curtain " + name + " is now " + (status ? "opened" : "closed"));
}
