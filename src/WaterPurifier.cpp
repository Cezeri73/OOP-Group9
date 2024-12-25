#include "WaterPurifier.h"

// Constructor to initialize the WaterPurifier object
WaterPurifier::WaterPurifier(const std::string &deviceName)
    : SmartDevice(deviceName), waterQuality(100) // Initialize water quality to 100 (excellent)
{
    this->type = Type::WaterPurifier; // Set the device type to "WaterPurifier"
    
    // Set up a repeat timeout that calls the decreaseQualityCallback function every 10 seconds
    Fl::repeat_timeout(10.0, WaterPurifier::decreaseQualityCallback, this);
}

// Destructor for the WaterPurifier class
WaterPurifier::~WaterPurifier()
{
    delete this; // Free the memory for the WaterPurifier object
}

// Callback function that decreases the water quality every 10 seconds
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

// Callback function for the water purifier device (handles the UI interaction)
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

// Getter function to retrieve the current water quality
int WaterPurifier::getWaterQuality() const
{
    return waterQuality; // Return the current water quality
}
