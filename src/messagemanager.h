/**
 * @file messagemanager.h
 * 
 * @brief This file contains the interface for how incoming messages will be
 *        handled.
 * @version 0.1
 * @date 2021-06-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "message.h"

// * All message retriever includes below *
#include "messageretriever.h"
#include "serialretriever.h"

#ifndef MESSAGERETRIEVER_PIO_H
#define MESSAGERETRIEVER_PIO_H

/**
 * @brief The class that will contain all operations
 *        for handling incoming messages. Message paring is not done here.
 *        This is like a message funnel. This will take all the different 
 *        message sources and combine them into a container that will
 *        appear like a single source for messages. 
 * 
 */
class MessageManager{

public:
    MessageManager(); 
    ~MessageManager(); 

    /**
     * @brief returns a new message if there is one available. If there
     *        is no new available message, then this class will return
     *        a nullptr. 
     * 
     * @return char* 
     */
    Message * getNewMessage(); 
    
private: 

    // All the different places that messages can come from.
    static const int num_sources = 1;
    MessageRetrieverBase * message_sources[1] = { new SerialRetriever() }; 

    // The source index allows for easy scanning of all the different indexs. 
    unsigned int source_index = 0;      

};

#endif 