#ifndef VIEW_H
#define VIEW_H

#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include "Controller.h"

class View {
private:
    Fl_Button* button;

public:
    View(Fl_Window* window, const std::string& label, int x, int y, int w, int h, Controller* controller);
};

#endif
