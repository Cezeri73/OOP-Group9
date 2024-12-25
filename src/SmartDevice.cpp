#include "SmartDevice.h"
#include "Light.h"

// Initialize a static notification buffer for all SmartDevice objects
Fl_Text_Buffer *SmartDevice::notificationBuffer = new Fl_Text_Buffer();

// Adds a notification message to the notification buffer
void SmartDevice::addNotification(const std::string &message)
{
    // Append the message followed by a newline character to the buffer
    notificationBuffer->append((message + "\n").c_str());
}

// Returns the name of the SmartDevice as a C-style string
const char *SmartDevice::getName()
{
    return name.c_str(); // Convert and return the name as a C-style string
}

// Serializes the SmartDevice object to a JSON representation
json SmartDevice::toJson() const
{
    // Create a JSON object with the device type
    return json{{"type", type}};
}

// Deserializes a SmartDevice object from a JSON representation
SmartDevice *SmartDevice::fromJson(const json &j)
{
    // Extract the device type from the JSON
    std::string type = j.at("type").get<std::string>();

    // Create and return a new device object based on the type
    if (type == "Light")
    {
        return new Light("Light"); // Return a new Light device if the type matches
    }
    return nullptr; // Return nullptr if the type is unrecognized
}
