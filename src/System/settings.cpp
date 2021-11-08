/**
 * @file settings.cpp
 * 
 * @brief Implemention of settings.h
 * @version 0.1
 * @date 2021-08-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "System/settings.h"
#include "System/interface.h"

Settings::SettingsInitErr Settings::InitializeSettings(){
    MainThread::LED::_InitializeLEDSettings();
    network::WIFI::_InitializeWifiSettings();
    bluetooth::_initializeBTSettings();

    return SettingsInitErr::OK; 
}

bool Settings::MainThread::LED::_InitializeLEDSettings(){
    return true;
}

bool Settings::bluetooth::_initializeBTSettings(){
    bluetooth_enabled = Interface::interface_enabled(Interface::Interfaces::BT);
    return true;
}

bool Settings::network::WIFI::_InitializeWifiSettings(){
    network_enabled = Interface::interface_enabled(Interface::Interfaces::WIFI);
    return true;
}
