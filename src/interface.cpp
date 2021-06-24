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

template<Interface::Interfaces I>
bool Interface::enabled(){

    //Sets the needed byte for the enabled file in the FS.
    interface_file[3] = static_cast<char> (I); 

    return Filesystem::file_exists(interface_file); 
}