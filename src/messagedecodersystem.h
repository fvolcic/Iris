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

#include "message.h"
#include "ArduinoJson.h"
#include "globals.h"

/**
 * @brief Contains all the decoder system functions.
 * 
 * 
 */
namespace DecoderSystem{

    // The internal Static json object buffer
    StaticJsonDocument<MAX_MESSAGE_LENGTH> jsonObj;

    /**
     * @brief Decode and then execute a message object
     * 
     * @param Message::Message - The message object to decode
     * @returns Decode success status - True on success - False on failure
     */
    bool decode_execute(Message::Message * msg); 

};