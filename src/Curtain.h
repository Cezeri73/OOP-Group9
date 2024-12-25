/**
 * @file Curtain.h
 * @brief Header file for the Curtain class.
 */

#ifndef CURTAIN_H
#define CURTAIN_H

#include "SmartDevice.h"

/**
 * @class Curtain
 * @brief Represents a smart curtain device.
 */
class Curtain : public SmartDevice
{
public:
    /**
     * @brief Constructor to initialize a Curtain device.
     * @param deviceName Name of the curtain device.
     */
    Curtain(const std::string &deviceName);

    /**
     * @brief Opens the curtain.
     */
    void openCurtain();

    /**
     * @brief Closes the curtain.
     */
    void closeCurtain();

    /**
     * @brief Callback function for curtain-related actions.
     */
    void deviceCallback(Fl_Widget *, void *) override;
};

#endif
