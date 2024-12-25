/**
 * @file WaterPurifier.cpp
 * @brief Implementation of the WaterPurifier class, representing a smart water purifier device.
 */

#include "WaterPurifier.h"

/**
 * @brief Constructor for the WaterPurifier class.
 * 
 * Initializes the water purifier with a given name and sets the water quality to 100 (excellent).
 * Also sets the device type to "WaterPurifier" and schedules a recurring callback to decrease water quality.
 * 
 * @param deviceName The name of the water purifier device.
 */
WaterPurifier::WaterPurifier(const std::string &deviceName)
    : SmartDevice(deviceName), waterQuality(100) // Initialize water quality to 100 (excellent)
{
    this->type = Type::WaterPurifier; // Set the device type to "WaterPurifier"
    
    // Set up a repeat timeout that calls the decreaseQualityCallback function every 10 seconds
    Fl::repeat_timeout(10.0, WaterPurifier::decreaseQualityCallback, this);
}

/**
 * @brief Destructor for the WaterPurifier class.
 * 
 * Frees the memory allocated for the WaterPurifier object.
 */
WaterPurifier::~WaterPurifier()
{
    delete this; // Free the memory for the WaterPurifier object
}

/**
 * @brief Callback function to decrease the water quality over time.
 * 
 * Reduces the water quality by a specified amount every 10 seconds.
 * If water quality remains above 0, the callback is rescheduled.
 * 
 * @param data Pointer to the WaterPurifier object.
 */
void WaterPurifier::decreaseQualityCallback(void *data)
{
    // Cast the data pointer to a WaterPurifier object
    WaterPurifier *purifier = static_cast<WaterPurifier *>(data);

    int decrease = 1; // Amount by which water quality will decrease
    purifier->waterQuality -= decrease; // Decrease the water quality by the specified amount

    // If water quality is still above 0, call the decreaseQualityCallback again after 10 seconds
    if (purifier->getWaterQuality() > 0)
    {
        Fl::repeat_timeout(10.0, decreaseQualityCallback, data);
    }
}

/**
 * @brief Callback function for the water purifier device.
 * 
 * Handles UI interaction and displays a notification about the current water quality.
 * 
 * @param widget Pointer to the widget triggering the callback.
 * @param data Pointer to the WaterPurifier object.
 */
void WaterPurifier::deviceCallback(Fl_Widget *widget, void *data)
{
    // Cast the data pointer to a WaterPurifier object
    WaterPurifier *purifier = static_cast<WaterPurifier *>(data);

    int quality = purifier->waterQuality; // Get the current water quality

    // Check the water quality and add the appropriate notification
    if (quality < 50) // If water quality is below 50%
    {
        addNotification("Warning: Water quality is poor (" + std::to_string(getWaterQuality()) + "%).");
    }
    else // If water quality is 50% or higher
    {
        addNotification("Water quality is good (" + std::to_string(getWaterQuality()) + "%).");
    }
}

/**
 * @brief Retrieves the current water quality of the purifier.
 * 
 * @return The current water quality as a percentage.
 */
int WaterPurifier::getWaterQuality() const
{
    return waterQuality; // Return the current water quality
}
