/**
 * @file utils.cpp
 * 
 * @brief Contains the definitions of things defined in the utils.h file
 * @version 0.1
 * @date 2021-06-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "utils.h"
#include <Arduino.h>

#ifndef UTILS_CPP
#define UTILS_CPP

bool Utils::LEDSerial::serialInitialized = false;
char Utils::LEDSerial::finalSerialByte = '\0';

unsigned int Utils::random(){
    return esp_random(); // get a cryptographically secure random number
}

template<bool PASS_VAL, bool STRICT>
bool Utils::Asserts::runtime_assert(bool val){
    if(STRICT){
        if(PASS_VAL != val)
            Utils::Program::RESET(); // reset program
        return true; 
    }else{
        return PASS_VAL == val; 
    }
}

//                   *******************************************
//                   *                                         *
//                   *         LED Serial Implementation       *
//                   *                                         *
//                   *******************************************

void Utils::LEDSerial::initializeSerial(unsigned long baud_rate){
    if(!Utils::LEDSerial::serialInitialized){
        Serial.begin(baud_rate); 
        Utils::LEDSerial::serialInitialized = true; 
    }
}

template<typename T>
void Utils::LEDSerial::print(T datum){
    if(!Utils::LEDSerial::serialInitialized)
        Utils::LEDSerial::initializeSerial(); 
    Serial.print(datum); 
}

bool Utils::LEDSerial::serialAvailable(){
    return Serial.available(); 
}

bool Utils::LEDSerial::readSerialUntil(char endByte, char * buffer, unsigned int length, unsigned long timeout){
    Serial.setTimeout(timeout); 
    return Serial.readBytesUntil(endByte, buffer, length); 
}

#endif