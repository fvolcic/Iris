/**
 * @file responderserial.cpp
 * 
 * @brief Implementation of responderserial.h
 * @version 0.1
 * @date 2021-08-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "responderserial.h"
#include "utils.h"

SerialResponder::SerialResponder(){

}

SerialResponder::~SerialResponder(){

}

ResponderBase::ResponseError SerialResponder::enable_component(){
    Utils::LEDSerial::initializeSerial();
    return ResponderBase::ResponseError::OK;
}


ResponderBase::ResponseError SerialResponder::sendDataUntilByte(const char * data, char endByte, int length){

    if(length == -1) // print once end byte is met is length = -1
        length = __INT_MAX__; 
    
    Utils::LEDSerial::print_char_until(data, endByte, length);
    return ResponderBase::ResponseError::OK;
}

ResponderBase::ResponseError SerialResponder::sendDataUntilLength(const char * data, unsigned int length){
    Utils::LEDSerial::printSerialUntilLength(data, length);
    return ResponderBase::ResponseError::OK;
}