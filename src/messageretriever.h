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

    /**
     * @brief Given a buffer, this will destroy the given buffer. 
     * 
     */
    void destroyBuffer(char *); 

    /**
     * @brief This is the struct that will represent a message.
     *        This will provide an interface to destroy messages and read messags. 
     * 
     */
    struct Message{

        // This represents the current two different type of messsages.
        enum class MessageType { StaticMessage, DynamicMessage }; 

        /**
         * @brief Construct a new Message object
         * 
         * @param message - pointer to a message buffer
         * @param type - what is the type of memory used for the buffer. 
         * @param flag - flag is a pointer to the boolean flag
         */
        Message(char * message, MessageType type, bool * flag);

        char * operator()(); 

        void DestroyMessage();

    private:
        bool messageAlive = true; 
        MessageType msgType; 
        bool * finishedWriteFlag; 
        char * buffer; 
    };

protected:

    /**
     * @brief This will return a pointer to the next available write buffer.
     * 
     * @note All write buffers will have a size of MAX_MESSAGE_LENGTH (globals.h)
     * 
     * @return char* 
     */
    Message * getMessageBuffer(); 

    /**
     * @brief This tells the messageretriever that a message has been sucessfully written to the buffer.
     * 
     */
    void messageBufferWriteCompleted(); 

private:

    // Internal message buffer. This is where the first message is stored.
    char messageBuffer[MAX_MESSAGE_LENGTH]; 

    // This queue is for storing all messages.
    std::queue<Message *> messages; 

    // These are the flags that a message retriever class will need.
    // staticbufferAvailable will let us know the messageBuffer array is available to
    // be written to. The value of throwaway is not defined for the program, and is only there to
    // provide an unneeded value that can be set when needed for generality of different algorithms. 
    bool staticbufferAvailable = true; 
    bool throwaway = false; 

    /**
     * @brief Return a dynamically allocated message buffer
     * 
     * @return char* 
     */
    static char * getDynamicBuffer(){
        return new char[MAX_MESSAGE_LENGTH]; 
    }

};

#endif