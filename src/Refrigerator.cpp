/**
 * @file Refrigerator.cpp
 * @brief Implementation of the Refrigerator class, representing a smart refrigerator device.
 */

#include "Refrigerator.h"

/**
 * @brief Constructor for the Refrigerator class.
 * 
 * Initializes the refrigerator with a given device name and initial stock level.
 * Sets the device type to "Refrigerator."
 * 
 * @param deviceName The name of the refrigerator device.
 * @param initialStock The initial stock level in the refrigerator.
 */
Refrigerator::Refrigerator(const std::string &deviceName, int initialStock)
    : SmartDevice(deviceName)
{
    initialStock = 10; // Initialize the stock to 10 units
    this->type = Type::Refrigerator; // Set the device type to "Refrigerator"
}

/**
 * @brief Callback function for the stock update button.
 * 
 * Updates the stock level of the refrigerator based on the user's input.
 * 
 * @param widget Pointer to the widget triggering the callback.
 * @param data Pointer to the Refrigerator object.
 */
void stockButton(Fl_Widget *widget, void *data)
{
    Refrigerator *fridge = static_cast<Refrigerator *>(data); // Cast the data pointer to a Refrigerator object
    Fl_Input *stockInput = static_cast<Fl_Input *>(widget->parent()->child(0)); // Get the input widget for stock level
    const char *newStockStr = stockInput->value(); // Retrieve the input value as a string
    int newStock = std::stoi(newStockStr); // Convert the string to an integer
    fridge->adjustStock(newStock); // Update the stock level in the refrigerator
}

/**
 * @brief Callback function for the refrigerator's device-specific actions.
 * 
 * Displays notifications about the stock level and opens a window for updating the stock level.
 * 
 * @param widget Pointer to the widget triggering the callback.
 * @param data Pointer to the Refrigerator object.
 */
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

/**
 * @brief Checks the stock level and updates the refrigerator's status.
 * 
 * If the stock is below 5 units, the status is set to "Low Stock."
 * Otherwise, it is set to "Sufficient Stock."
 */
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

/**
 * @brief Adjusts the refrigerator's stock level.
 * 
 * Sets the stock level to the specified amount and ensures it is non-negative.
 * Generates a notification about the updated stock level and checks the stock status.
 * 
 * @param amount The new stock level to set.
 */
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

/**
 * @brief Gets the current stock level of the refrigerator.
 * 
 * @return The current stock level.
 */
int Refrigerator::getStockLevel() const
{
    return stockLevel; // Return the current stock level
}
