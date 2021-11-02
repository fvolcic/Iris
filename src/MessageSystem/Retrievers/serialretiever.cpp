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

#include "Utils/globals.h"
#include "MessageSystem/Retrievers/serialretriever.h"
#include "Utils/utils.h"
#include "MessageSystem/message.h"
#include "Utils/printer.h"

#ifndef SERIALRETIEVER_H
#define SERIALRETIEVER_H

void SerialRetriever::setupRetriever(){
    Utils::LEDSerial::initializeSerial(); 
}

void SerialRetriever::updateRetriever(){
    // PRINT("Running Update Serial\n");
    // First check if there is some new information available to be read. 
    if(!Utils::LEDSerial::serialAvailable())
        return; 
    
    Message * messageBuffer = this->getMessageBuffer(); // get the message buffer
    Utils::LEDSerial::readSerialUntil(Utils::LEDSerial::finalSerialByte, messageBuffer->begin()); // read the data into the message buffer 
    this->enqueue_message(messageBuffer); // Enqueue the new message
}

SerialRetriever::SerialRetriever(){}
SerialRetriever::~SerialRetriever(){}

#endif
