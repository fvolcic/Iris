/**
 * @file interface.h
 *
 * @brief This file represents a different interface options and their settings (BLE, WIFI, Serial).
 * @version 0.1
 * @date 2021-06-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "System/storage.h"

namespace Interface{

enum class Interfaces { WIFI, BT, ESP_SERIAL }; 

/**
 * @brief Check if a specific interface is enabled.
 * 
 * @param interface 
 * @return true 
 * @return false 
 */
bool interface_enabled(Interfaces interface);

/**
 * @brief Enable an iterface 
 * 
 * @param interface 
 * @return true 
 * @return false 
 */
bool enable_interface(Interfaces interface, bool reboot = false);

/**
 * @brief Disable an interface
 * 
 * @param interface 
 * @param reboot 
 * @return true 
 * @return false 
 */
bool disable_interface(Interfaces interface, bool reboot = false);
};
