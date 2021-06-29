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
#include "message.h"
#include "structures.h"

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

    //******************************************************************
    //* Below are the two virtual functions that need to be overriden. *
    //* These are the only two functions that must be implemented by a * 
    //* a base class. This are required for the retriever to work      *
    //* correctly.                                                     *
    //******************************************************************

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

    //*****************************************************************

    /**
     * @brief Check to see if there is a new message available from the message retriever.
     * 
     */
    bool isMessageAvailable(); 

    /**
     * @brief This will retrieve the most recent message from the message retriever.
     * 
     * @note You will have to call destroyMessage on this pointer when the pointer
     *       is no longer needed. 
     * 
     */
    Message * getNewMessage();
   

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
     * @brief Will add a message to the queue.
     * 
     * @note if there is no more room in the message queue, then the message will be ignored. 
     *       
     */
    void enqueue_message(Message *); 

private:

    // Internal message buffer. This is where the first message is stored.
    char messageBuffer[MAX_MESSAGE_LENGTH]; 

    // -> This queue is for storing all messages.
    // -> We are assuming that no more than 5 messages will be in the queue at a single time.
    //    If this assumption is ill formed, then the queue can be expanded by altering the
    //    second template parameter. For this to compile, structures.cpp also needs to be
    //    edited to contain the template class instantiaion info for queue of size 5.
    ledstd::RingBuffer<Message *, 5u> messages; 

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