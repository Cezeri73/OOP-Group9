#ifndef CURTAIN_H
#define CURTAIN_H

#include "SmartDevice.h"

class Curtain : public SmartDevice {
public:
   	Curtain(const std::string& deviceName);
  	void openCurtain();
    	void closeCurtain(); 
	void deviceCallback(Fl_Widget*,void*) override;
    	std::string getStatus() const override; 
};

#endif // CURTAIN_H
