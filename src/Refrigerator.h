#ifndef REFRIGERATOR_H
#define REFRIGERATOR_H

#include "SmartDevice.h"
#include <string>

class Refrigerator : public SmartDevice {
private:
    int stockLevel; // Mevcut stok seviyesi

public:
    // Constructor
    Refrigerator(const std::string& deviceName, int initialStock = 10)
        : SmartDevice(deviceName), stockLevel(initialStock) {}

    // Stok kontrol fonksiyonu
    void checkStock() {
        if (stockLevel < 5) {
            status = "Low Stock";
        } else {
            status = "Sufficient Stock";
        }
    }

    // Stok ayarlama fonksiyonu
    void adjustStock(int amount) {
        stockLevel += amount;
        if (stockLevel < 0) {
            stockLevel = 0; // Negatif stok seviyesine izin verme
        }
        checkStock();
    }

    // Mevcut stok seviyesini döndüren fonksiyon
    int getStockLevel() const {
        return stockLevel;
    }

    // Durumu döndüren fonksiyon
    std::string getStatus() const override {
        return "Stock Level: " + std::to_string(stockLevel) + " | Status: " + status;
    }
};

#endif // REFRIGERATOR_H
