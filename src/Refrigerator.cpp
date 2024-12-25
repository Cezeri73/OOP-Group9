#include "Refrigerator.h"

// Constructor for the Refrigerator class
Refrigerator::Refrigerator(const std::string &deviceName, int initialStock)
    : SmartDevice(deviceName)
{
    initialStock = 10; // Initialize the stock to 10 units
    this->type = Type::Refrigerator; // Set the device type to "Refrigerator"
}

// Callback function for the stock update button
void stockButton(Fl_Widget *widget, void *data)
{
    Refrigerator *fridge = static_cast<Refrigerator *>(data); // Cast the data pointer to a Refrigerator object
    Fl_Input *stockInput = static_cast<Fl_Input *>(widget->parent()->child(0)); // Get the input widget for stock level
    const char *newStockStr = stockInput->value(); // Retrieve the input value as a string
    int newStock = std::stoi(newStockStr); // Convert the string to an integer
    fridge->adjustStock(newStock); // Update the stock level in the refrigerator
}

// Callback function for the refrigerator's device-specific actions
void Refrigerator::deviceCallback(Fl_Widget *widget, void *data)
{
    Refrigerator *fridge = static_cast<Refrigerator *>(data); // Cast the data pointer to a Refrigerator object

    // Check the current stock level and add appropriate notifications
    if (fridge->getStockLevel() < 5)
    {
        addNotification("Warning: Refrigerator stock is low (" + std::to_string(fridge->getStockLevel()) + ").");
    }
    else
    {
        addNotification("Refrigerator stock is sufficient (" + std::to_string(fridge->getStockLevel()) + ").");
    }

    // Create a window for updating the refrigerator's stock level
    Fl_Window *fridgeWindow = new Fl_Window(400, 200, "Refrigerator - Update Stock");
    Fl_Input *stockInput = new Fl_Input(150, 50, 100, 30, "Enter new stock level:"); // Input field for new stock level
    Fl_Button *updateStockButton = new Fl_Button(150, 100, 100, 40, "Update Stock"); // Button to update stock level
    updateStockButton->callback(stockButton, fridge); // Set callback for the update stock button

    fridgeWindow->end(); // Finalize the layout of the window
    fridgeWindow->show(); // Display the window
}

// Check the stock level and update the status
void Refrigerator::checkStock()
{
    if (stockLevel < 5) // If stock is below 5 units
    {
        status = "Low Stock"; // Set status to "Low Stock"
    }
    else
    {
        status = "Sufficient Stock"; // Set status to "Sufficient Stock"
    }
}

// Adjust the refrigerator's stock level
void Refrigerator::adjustStock(int amount)
{
    stockLevel = amount; // Set the stock level to the given amount
    if (stockLevel < 0) // Ensure stock level is not negative
    {
        stockLevel = 0;
    }
    // Add a notification about the updated stock level
    addNotification("Stock updated. New stock level: " + std::to_string(this->getStockLevel()) + ".");
    checkStock(); // Check the stock level and update the status
}

// Get the current stock level of the refrigerator
int Refrigerator::getStockLevel() const
{
    return stockLevel; // Return the current stock level
}
