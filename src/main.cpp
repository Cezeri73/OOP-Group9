#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include "Curtain.h"
#include "Light.h"
#include "NotificationSystem.h"

int main() {
    // Ana pencere
    Fl_Window* window = new Fl_Window(800, 600, "Smart Home Simulation");

    // Arka plan resmi
    Fl_Box* background = new Fl_Box(0, 0, 800, 600);
    Fl_JPEG_Image* bgImage = new Fl_JPEG_Image("home_background.jpg");
    background->image(bgImage);

    // Bildirim sistemi
    NotificationSystem notification;
/*
    // Perde kontrolü
    Fl_Box* curtainBox = new Fl_Box(100, 100, 200, 200);
    Curtain* curtain = new Curtain("Living Room Curtain", curtainBox);
    curtain->addObserver(&notification);

    Fl_Button* curtainButton = new Fl_Button(100, 320, 200, 30, "Toggle Curtain");
    curtainButton->callback([](Fl_Widget*, void* data) {
        static_cast<Curtain*>(data)->toggle();
    }, curtain);

    // Işık kontrolü
    Fl_Box* lightBox = new Fl_Box(400, 100, 200, 200);
    Light* light = new Light("Bedroom Light", lightBox);
    light->addObserver(&notification);

    Fl_Button* lightButton = new Fl_Button(400, 320, 200, 30, "Toggle Light");
    lightButton->callback([](Fl_Widget*, void* data) {
        static_cast<Light*>(data)->toggle();
    }, light);
*/
    // Pencereyi başlat
    window->end();
    window->show();

    return Fl::run();
}
