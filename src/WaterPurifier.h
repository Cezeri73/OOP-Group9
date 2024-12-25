/**
 * @file WaterPurifier.h
 * @brief Header file for the WaterPurifier class, representing a smart water purifier device.
 */

#ifndef WATERPURIFIER_H
#define WATERPURIFIER_H

#include "SmartDevice.h"
#include <string>
#include <cstdlib>
#include <ctime>

/**
 * @class WaterPurifier
 * @brief Represents a smart water purifier in the smart home system.
 * 
 * The WaterPurifier class monitors water quality, decreases quality over time,
 * and provides user interaction to check and manage the device's state.
 */
class WaterPurifier : public SmartDevice
{
private:
    int waterQuality; ///< Current water quality percentage (0-100).

public:
    /**
     * @brief Constructor for the WaterPurifier class.
     * 
     * Initializes the water purifier with a given name and sets the water quality to 100 (excellent).
     * 
     * @param deviceName The name of the water purifier device.
     */
    WaterPurifier(const std::string &deviceName);

    /**
     * @brief Destructor for the WaterPurifier class.
     * 
     * Cleans up resources associated with the WaterPurifier object.
     */
    ~WaterPurifier();

    /**
     * @brief Callback function for the water purifier device.
     * 
     * Handles UI interaction and displays notifications about the current water quality.
     * 
     * @param widget Pointer to the widget triggering the callback.
     * @param data Pointer to the WaterPurifier object.
     */
    void deviceCallback(Fl_Widget *, void *) override;

    /**
     * @brief Retrieves the current water quality of the purifier.
     * 
     * @return The current water quality as a percentage.
     */
    int getWaterQuality() const;

    /**
     * @brief Callback function to decrease water quality over time.
     * 
     * This function is called at regular intervals to simulate a decrease in water quality.
     * 
     * @param data Pointer to the WaterPurifier object.
     */
    static void decreaseQualityCallback(void *data);
};

#endif // WATERPURIFIER_H
