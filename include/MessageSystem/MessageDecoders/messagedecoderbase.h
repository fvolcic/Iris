/**
 * @file messagedecoderbase.h
 * 
 * @brief This file contains information regaurding the base class message parser.
 * @version 0.1
 * @date 2021-07-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "ArduinoJson.h"

#ifndef MESSAGEDECODERBASE_H
#define MESSAGEDECODERBASE_H

/**
 * @brief This decodes a specific message type. Once the message is decoded, 
 *        this class will then execute all needed operations.
 * 
 */
class MessageDecoderBase{

public:

    MessageDecoderBase(); 
    ~MessageDecoderBase(); 

    /**
     * @brief This will decode the actual message and then execute
     *        the needed operations. 
     * 
     * @return true 
     * @return false 
     */
    virtual bool decode(JsonDocument * doc) = 0;

    /**
     * @brief Check to see if a string matches the message key.
     * 
     * @note For example, if this message decoder was meant to decode a "ACTIONMESSAGE" and the
     *       key of an action message was "action-message", then a '\0'-terminated string that
     *       represents the action key will return true, and all others will return false.
     * 
     * @param str 
     * @return true 
     * @return false 
     */
    bool compare(const char * str);

protected:

    /**
     * @brief Get the key object as a pointer.
     * 
     * @note key is null terminated. 
     * 
     * @param key 
     * @return char* 
     */
    virtual const char * get_key() = 0; 

};

#endif
