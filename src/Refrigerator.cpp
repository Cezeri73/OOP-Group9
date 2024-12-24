#include "Refrigerator.h"

    // Constructor
Refrigerator::Refrigerator(const std::string& deviceName, int initialStock)
        : SmartDevice(deviceName) {
		initialStock = 10;
        this->type=Type::Refrigerator;
	}
void stockButton(Fl_Widget* widget, void* data){
        Refrigerator* fridge = static_cast<Refrigerator*>(data);
        Fl_Input* stockInput = static_cast<Fl_Input*>(widget->parent()->child(0)); 
        const char* newStockStr = stockInput->value(); 
        int newStock = std::stoi(newStockStr); 
        fridge->adjustStock(newStock);
}
void Refrigerator::deviceCallback(Fl_Widget* widget,void* data) {
    Refrigerator* fridge = static_cast<Refrigerator*>(data);
    if (fridge->getStockLevel() < 5) {
        addNotification("Warning: Refrigerator stock is low (" + std::to_string(fridge->getStockLevel()) + ").");
    } else {
        addNotification("Refrigerator stock is sufficient (" + std::to_string(fridge->getStockLevel()) + ").");
    }
    
    Fl_Window* fridgeWindow = new Fl_Window(400, 200, "Refrigerator - Update Stock");
    Fl_Input* stockInput = new Fl_Input(150, 50, 100, 30, "Enter new stock level:");
    Fl_Button* updateStockButton = new Fl_Button(150, 100, 100, 40, "Update Stock");
    updateStockButton->callback(stockButton,fridge);

    fridgeWindow->end();
    fridgeWindow->show();
}
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
        stockLevel = amount;
        if (stockLevel < 0) {
            stockLevel = 0; // Negatif stok seviyesine izin verme
        }
        addNotification("Stock updated. New stock level: " + std::to_string(this->getStockLevel()) + ".");
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
