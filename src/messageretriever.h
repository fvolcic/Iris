/**
 * @file messageretriever.h
 * 
 * @brief Message retriever base class for the led light strip.
 * @version 0.1
 * @date 2021-06-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "globals.h"

#include <queue>

#ifndef MESSAGERETRIEVER_H
#define MESSAGERETRIEVER_H

/**
 * @brief Create the base class for the message retreiver.
 *        All different ways of retrieving messages must be
 *        done using through the MessageRetrieverBase class.
 * 
 */
class MessageRetrieverBase {

public:

    /**
     * @brief Setup all necessary functions that will be needed for the message retriever.
     * 
     */
    virtual void setupRetriever() = 0; 

    /**
     * @brief This function will run an update on the retreiver. This will allow the retiever to
     *        seek for an incoming message if there is one.
     * 
     */
    virtual void updateRetriever() = 0;

    /**
     * @brief Check to see if there is a new message available from the message retriever.
     * 
     */
    bool isNewMessage(); 

    /**
     * @brief This will retrieve the most recent message from the message retriever.
     * 
     */
    char * getNewMessage();

protected:

    /**
     * @brief This will return a pointer to the next available write buffer.
     * 
     * @note All write buffers will have a size of MAX_MESSAGE_LENGTH (globals.h)
     * 
     * @return char* 
     */
    char * getWriteBuffer(); 

    /**
     * @brief This tells the messageretriever that a message has been sucessfully written to the buffer.
     * 
     */
    void messageBufferWriteCompleted(); 

private:

    // Internal message buffer. This is where the first message is stored.
    char messageBuffer[MAX_MESSAGE_LENGTH]; 

    // If the message buffer is full, then additional messages will need to be stored
    // in the dynamic message buffer for processing after the first message. 
    std::queue<char *> dynamicMessageBuffer; 

    std::queue<char *> 

};

#endif