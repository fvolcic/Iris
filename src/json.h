/**
 * @file json.h
 * @brief File contains the functions and classes surrounding what is available in terms of JSON
 * @version 0.1
 * @date 2021-08-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "message.h"

namespace JSON{

    /**
     * @brief The JSON object. This contains all the needed functionality to interface with json objects.
     * 
     */
    class JSON{
    
    public:

        JSON() = delete;
    
        /**
         * @brief Construct a new JSON object from a char * 
         * 
         * @param str 
         */
        JSON(char * str);

        /**
         * @brief Construct a new JSON object from a Message::Message
         * 
         * @param JSON_msg 
         */
        JSON(Message::Message * JSON_msg);
       
    };



};