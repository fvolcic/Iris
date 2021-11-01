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

void Utils::LEDSerial::print_char_until(const char * buffer, char endbyte, int length){
    if(!Utils::LEDSerial::serialInitialized)
        Utils::LEDSerial::initializeSerial(); 
    for(int i = 0; i < length; ++i){
        if(buffer[i] == endbyte)
            return; 
        Utils::LEDSerial::print(buffer[i]);
    }
}

void Utils::LEDSerial::printSerialUntilLength(const char * buffer, unsigned int length){
    for(unsigned int i = 0; i < length; ++i)
        Utils::LEDSerial::print(buffer[i]);
}

void (*Utils::Program::RESET)(void) = 0;



// template instantions
template void Utils::LEDSerial::print(char *); 
template void Utils::LEDSerial::print(char const *); 
template void Utils::LEDSerial::print(bool); 
template void Utils::LEDSerial::print(unsigned int);
template void Utils::LEDSerial::print(int);

#endif