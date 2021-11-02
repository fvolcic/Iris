/**
 * @file messagedecodersystem.h
 * 
 * @brief This file outlines the functions that are available for message decoding
 * @version 0.1
 * @date 2021-08-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "ArduinoJson.h"
#include "Utils/globals.h"
#include "MessageSystem/message.h"
#include "MessageSystem/MessageDecoders/messagedecoderbase.h"

// Decoders
#include "MessageSystem/MessageDecoders/messagedecodertest.h"

#ifndef MESSAGEDECODER_H
#define MESSAGEDECODER_H

/**
 * @brief Contains all the decoder system functions.
 * 
 * 
 */
namespace DecoderSystem{

    // The internal Static json object buffer
    extern StaticJsonDocument<MAX_MESSAGE_LENGTH> jsonObj;

    // The different decoders are defined here
    extern ExampleDecoder exampledecoder; 

    // Storage for the different internal message decoder classes
    extern unsigned int num_decoders;// = 1;
    extern MessageDecoderBase * decoders[];// = {&exampledecoder}; 

    /**
     * @brief Decode and then execute a message object
     * 
     * @param Message::Message - The message object to decode
     * @returns Decode success status - True on success - False on failure
     */
    bool decode_execute(Message * msg); 

};

#endif
