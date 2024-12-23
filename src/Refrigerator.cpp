#include "Refrigerator.h"

    // Constructor
Refrigerator::Refrigerator(const std::string& deviceName, int initialStock)
        : SmartDevice(deviceName) {
		initialStock = 10;
	}
void Refrigerator::deviceCallback(Fl_Widget* widget,void* data) {
    Refrigerator* fridge = static_cast<Refrigerator*>(data);
    if (fridge->getStockLevel() < 5) {
        addNotification("Warning: Refrigerator stock is low (" + std::to_string(fridge->getStockLevel()) + ").");
    } else {
        addNotification("Refrigerator stock is sufficient (" + std::to_string(fridge->getStockLevel()) + ").");
    }


};
    // Stok kontrol fonksiyonu
    void Refrigerator::checkStock() {
        if (stockLevel < 5) {
            status = "Low Stock";
        } else {
            status = "Sufficient Stock";
        }
    }

    // Stok ayarlama fonksiyonu
    void Refrigerator::adjustStock(int amount) {
        stockLevel += amount;
        if (stockLevel < 0) {
            stockLevel = 0; // Negatif stok seviyesine izin verme
        }
        checkStock();
    }

    // Mevcut stok seviyesini döndüren fonksiyon
    int Refrigerator::getStockLevel() const {
        return stockLevel;
    }

    // Durumu döndüren fonksiyon
    std::string Refrigerator::getStatus() const {
        return "Stock Level: " + std::to_string(stockLevel) + " | Status: " + status;
    }
