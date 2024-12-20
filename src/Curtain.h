#ifndef CURTAIN_H
#define CURTAIN_H

#include "SmartDevice.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.H>

class Curtain : public SmartDevice {
private:
    Fl_Box* box;
    Fl_JPEG_Image* openImage;
    Fl_JPEG_Image* closedImage;

public:
    Curtain(const std::string& deviceName, Fl_Box* box);
    void toggle() override;
};

#endif
