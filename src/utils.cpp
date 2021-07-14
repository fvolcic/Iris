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

unsigned int Utils::random(){
    return esp_random(); // get a cryptographically secure random number
}

template<bool PASS, bool STRICT>
bool Utils::Asserts::assert(bool val){
    if(STRICT){
        if(PASS != val)
            Utils::Program::RESET(); // reset program
        return true; 
    }else{
        return PASS == val; 
    }
    
}