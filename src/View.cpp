#include "View.h"

View::View(Fl_Window* window, const std::string& label, int x, int y, int w, int h, Controller* controller) {
    button = new Fl_Button(x, y, w, h, label.c_str());
    button->callback([](Fl_Widget*, void* data) {
        Controller* ctrl = static_cast<Controller*>(data);
        ctrl->toggleDevice();
    }, controller);
}
