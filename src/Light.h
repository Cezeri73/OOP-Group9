#ifndef LIGHT_H
#define LIGHT_H

#include "SmartDevice.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.H>

class Light : public SmartDevice {
private:
    Fl_Box* box;
    Fl_JPEG_Image* onImage;
    Fl_JPEG_Image* offImage;

public:
    Light(const std::string& deviceName, Fl_Box* box);
    void toggle() override;
};

#endif
