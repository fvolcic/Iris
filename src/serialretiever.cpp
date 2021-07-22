/**
 * @file serialretiever.cpp
 *
 * @brief Definition of class defined in serialreriever.h
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <Arduino.h>

#include "globals.h"
#include "serialretriever.h"
#include "utils.h"

void SerialRetriever::setupRetriever(){
    Utils::LEDSerial::initializeSerial(); 
}

void SerialRetriever::updateRetriever(){
    
}