/**
 * @file Refrigerator.h
 * @brief Header file for the Refrigerator class, representing a smart refrigerator device.
 */

#ifndef REFRIGERATOR_H
#define REFRIGERATOR_H

#include "SmartDevice.h"
#include <string>

/**
 * @class Refrigerator
 * @brief Represents a smart refrigerator in the smart home system.
 * 
 * This class provides functionality to manage and monitor the stock level 
 * of a refrigerator, including notifications for low stock and the ability 
 * to adjust stock levels.
 */
class Refrigerator : public SmartDevice
{
private:
    int stockLevel = 0; ///< Current stock level in the refrigerator.

public:
    /**
     * @brief Constructor for the Refrigerator class.
     * 
     * Initializes the refrigerator with a given device name and an initial stock level.
     * 
     * @param deviceName Name of the refrigerator device.
     * @param initialStock Initial stock level (default is 10 units).
     */
    Refrigerator(const std::string &deviceName, int initialStock = 10);

    /**
     * @brief Callback function for handling device-specific actions.
     * 
     * This function displays notifications about the refrigerator's stock level
     * and allows users to update the stock via a UI.
     * 
     * @param widget Pointer to the triggering widget.
     * @param data User-defined data, expected to be a Refrigerator object.
     */
    void deviceCallback(Fl_Widget *, void *) override;

    /**
     * @brief Checks the current stock level and updates the status accordingly.
     * 
     * Sets the status to "Low Stock" if the stock level is below 5, otherwise sets it to "Sufficient Stock."
     */
    void checkStock();

    /**
     * @brief Adjusts the refrigerator's stock level.
     * 
     * Updates the stock level to the specified amount. If the stock level is below zero,
     * it is reset to zero. Generates a notification about the updated stock level.
     * 
     * @param amount The new stock level to set.
     */
    void adjustStock(int amount);

    /**
     * @brief Retrieves the current stock level of the refrigerator.
     * 
     * @return The current stock level.
     */
    int getStockLevel() const;

    std::string status; ///< Current status of the refrigerator (e.g., "Low Stock").
};

#endif // REFRIGERATOR_H
