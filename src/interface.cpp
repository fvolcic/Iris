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

#include "interface.h"
#include "storage.h"

bool Interface::interface_enabled(Interface::Interfaces interface){
    switch(interface){
        case Interfaces::BT:
            return !Filesystem::file_exists("/BT");
        break;

        case Interfaces::WIFI:
            return Filesystem::file_exists("/WIFI");
        break; 

        case Interfaces::SERIAL:
            return Filesystem::file_exists("/SERIAL");
        break;
    }
}

bool Interface::enable_interface(Interface::Interfaces interface){
    switch(interface){
        case Interfaces::BT:
            return Filesystem::create_file("/BT");
        break;

        case Interfaces::WIFI:
            return Filesystem::create_file("/WIFI");
        break; 

        case Interfaces::SERIAL:
            return Filesystem::create_file("/SERIAL");
        break;
    }
}

bool Interface::disable_interface(Interface::Interfaces interface){
    switch(interface){
        case Interfaces::BT:
            return Filesystem::delete_file("/BT");
        break;

        case Interfaces::WIFI:
            return Filesystem::delete_file("/WIFI");
        break; 

        case Interfaces::SERIAL:
            return Filesystem::delete_file("/SERIAL");
        break;
    }
}