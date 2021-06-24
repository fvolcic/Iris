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

#include "storage.h"

namespace Interface{

enum class Interfaces { WIFI, MQTT, BT, SERIAL }; 

char interface_file[] = {"/", "I", "F", "0", "\0"}; 

template<Interface::Interfaces I>
bool enabled(); 

};