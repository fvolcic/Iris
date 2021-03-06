/**
 * @file interface.cpp
 * 
 * @brief Definitions for interface.h
 * @version 0.1
 * @date 2021-06-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "System/interface.h"
#include "System/storage.h"
#include "Utils/utils.h"

bool Interface::interface_enabled(Interface::Interfaces interface){
    switch(interface){
        case Interfaces::BT:
            return !Filesystem::file_exists("/BT");
        break;

        case Interfaces::WIFI:
            return Filesystem::file_exists("/WIFI");
        break; 

        case Interfaces::ESP_SERIAL:
            return Filesystem::file_exists("/SERIAL");
        break;
    }
    return false;
}

bool Interface::enable_interface(Interface::Interfaces interface, bool reboot){
    bool success = false; 
    switch(interface){
        case Interfaces::BT:
            success = Filesystem::create_file("/BT");
        break;

        case Interfaces::WIFI:
            success = Filesystem::create_file("/WIFI");
        break; 

        case Interfaces::ESP_SERIAL:
            success = Filesystem::create_file("/SERIAL");
        break;
    }

    if(reboot)
        Utils::Program::RESET();
    
    return success;
}

bool Interface::disable_interface(Interface::Interfaces interface, bool reboot){
    bool success = false;
    switch(interface){
        case Interfaces::BT:
            success = Filesystem::delete_file("/BT");
        break;

        case Interfaces::WIFI:
            success = Filesystem::delete_file("/WIFI");
        break; 

        case Interfaces::ESP_SERIAL:
            success = Filesystem::delete_file("/SERIAL");
        break;
    }

    if(reboot)
        Utils::Program::RESET();
    
    return success;
}
