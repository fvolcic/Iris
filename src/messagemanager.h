/**
 * @file messagemanager.h
 *
 * @brief Contains the details on how to manage messages from different sources. 
 * @version 0.1
 * @date 2021-06-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <queue>

#include "messageretriever.h"
#include "ledaction.h"


#ifndef MESSAGEMANAGEMENT_H
#define MESSAGEMANAGEMENT_H

namespace MessageManagement{

/**
 * @brief Enum class represents type of a given message. 
 * 
 */
enum class MessageType { ActionMessage, CommandMessage }; 

/**
 * @brief This returns the type of a given command. 
 * 
 */
enum class Command { Brightness, Clear, OTAUpate }; 

struct LEDActionData{
    int layer; 
    int actionGroup; 
};

/**
 * @brief Class that manages all the different types of messages. 
 * 
 */
class MessageManager{

public: 

    /**
     * @brief Launch a message manager thread. This will update internal variables.
     * 
     */
    MessageManager(); 
    ~MessageManager(); 

    /**
     * @brief Check the message manager for new incoming messages from 
     *        any one of the given sources.
     * 
     * @return true 
     * @return false 
     */
    bool isNewMessage();

    /**
     * @brief Return the type of the most recent message. 
     * 
     * @return MessageManagement::MessageType 
     */
    MessageManagement::MessageType getMessageType();

    /**
     * @brief This will parse an action message and return an LED action in response. 
     * 
     * @return LEDAction 
     */
    LEDAction * parseActionMessage();

    /**
     * @brief 
     * 
     */

private:

    bool isNewMessage_v = false; // Do any of the sources have a new messaeg. 

    int sourceIndex = 0; // What is the current index for searching for messags.

    //Fill this with each message source.
    mutable const MessageRetrieverBase const * messageSources[] = {/*Fill message sources here.*/};  
    static constexpr int num_sources = 0; 

};



}; 

#endif