#ifndef REFRIGERATOR_H
#define REFRIGERATOR_H

#include "SmartDevice.h"
#include <string>

class Refrigerator : public SmartDevice {
private:
    int stockLevel; // Mevcut stok seviyesi

public:
    // Constructor
    Refrigerator(const std::string& deviceName, int initialStock = 10);
void deviceCallback(Fl_Widget*,void*) override;
    void checkStock() ;
    void adjustStock(int amount) ;
    int getStockLevel() const ;
    std::string getStatus() const override ;
};

#endif // REFRIGERATOR_H
