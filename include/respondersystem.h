/**
 * @file respondersystem.h
 * 
 * @brief Decleration of the responder system allowing the user to send responses.
 * @version 0.1
 * @date 2021-08-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "enum.h"
#include "responderbase.h"

#ifndef RESPONDERSYS_H
#define RESPONDERSYS_H

namespace Respond
{

    /**
     * @brief Different errors that can be returned.
     * 
     */
    enum class ResponderError
    {
        OK,
        AlreadyEnabled,
        AlreadyDisabled,
        FailedToEnableSome,
        FailedToDisableSome,
        FailedToDisable,
        FailedToEnable,
        UnknownError
    };

    /**
     * @brief The different possible responders that can be used.
     * 
     */
    ENUM(Responders, HardwareSerial); // Serial enum class where you can determine size in code
    extern ResponderBase *Responder_Pointers[];

    //enum class responders{SerialBT, HardwareSerial};

    /**
     * @brief enable a responder that the system is able to respond with
     * 
     * @param responder - which responder would you like to enable
     * @param clear_others - default false. If anything is currently enabled, first disable, then
     *                       enable the new responder
     * 
     * @return responderError 
     */
    ResponderError enableReponder(Responders responder, bool clear_others = false);

    /**
     * @brief Disable a given responder
     * 
     * @param responder 
     * @return responderError 
     */
    ResponderError disableResponder(Responders responder);

    /**
     * @brief enable all different responders in the code
     * 
     * @return responderError 
     */
    ResponderError enableAllResponders();

    /**
     * @brief Disable all responders
     * 
     * @return responderError 
     */
    ResponderError disableAllResponders();

    /**
     * @brief Send data until a specific byte is reached or a specific length
     * 
     * @note if length = -1, then only endByte can terminate the data being sent.
     * 
     * @param data 
     * @param endByte 
     * @return ResponderError 
     */
    ResponderError sendDataUntilByte(const char *data, char endByte, int length = -1);

    /**
     * @brief Send a char array of data, where the length of the char array is length
     * 
     * @param data 
     * @param length 
     * @return ResponderError 
     */
    ResponderError sendDataUntilLength(const char *data, unsigned int length);

    // A list that has enough space to contain all possible responders
    extern Responders enabledResponders[];//[ENUMSIZE(Responders, unsigned int)];

    // The number of enabled responders
    extern unsigned int num_enabled_responders;

    // The number of responders that current exist
    extern const unsigned int num_responders;// = ENUMSIZE(Responders, unsigned int);
};

#endif