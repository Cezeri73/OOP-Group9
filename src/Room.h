/**
 * @file Room.h
 * @brief Header file for the Room class, representing rooms in the smart home system.
 */

#pragma once

#include "SmartDevice.h"
#include "Light.h"
#include <iostream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include "AddDeviceScreen.h"
#include "RemoveDeviceScreen.h"
#include "Light.h"
#include "Thermostat.h"
#include "Curtain.h"
#include "SecurityCamera.h"
#include "WaterPurifier.h"
#include "Elevator.h"
#include "Refrigerator.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

/**
 * @class Room
 * @brief Represents a room in the smart home system.
 * 
 * The Room class manages smart devices within a room, allowing users to add, 
 * remove, and interact with devices. It also supports serialization and 
 * deserialization for saving and loading room configurations.
 */
class Room
{
private:
    std::vector<SmartDevice *> devices; ///< List of smart devices in the room.
    AddDeviceScreen ads; ///< Screen for adding a device to the room.
    RemoveDeviceScreen rds; ///< Screen for removing a device from the room.

public:
    static std::vector<Room *> allRooms; ///< List of all room instances.
    std::string roomName; ///< Name of the room.

    /**
     * @brief Constructor for the Room class.
     * 
     * Initializes a room with a given name and adds it to the list of all rooms.
     * 
     * @param name The name of the room.
     */
    Room(std::string &name);

    /**
     * @brief Displays the room interface.
     * 
     * Creates a UI for managing devices and actions within the room.
     */
    void showRoom();

    /**
     * @brief Adds a new device to the room based on user selection.
     * 
     * @param selection Index of the selected device type.
     */
    void addDevice(int selection);

    /**
     * @brief Removes a device from the room by its type.
     * 
     * @param type The type of device to remove.
     */
    void removeDevice(int type);

    /**
     * @brief Compares two rooms for equality based on their names.
     * 
     * @param otherRoom The room to compare with.
     * @return True if the rooms have the same name, false otherwise.
     */
    bool operator==(Room &otherRoom);

    /**
     * @brief Serializes the room data to JSON format.
     * 
     * Converts the room and its devices into a JSON representation for saving.
     * 
     * @return JSON representation of the room and its devices.
     */
    json toJson() const;

    /**
     * @brief Deserializes room data from JSON format.
     * 
     * Creates a room instance and its devices from a JSON representation.
     * 
     * @param j JSON representation of the room.
     */
    static void fromJson(const json &j);

    /**
     * @brief Adds a device directly to the room.
     * 
     * This method is typically used during deserialization.
     * 
     * @param device Pointer to the SmartDevice to add.
     */
    void addDevice(SmartDevice *device);
};
