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
    virtual void isNewMessage() = 0; 

    /**
     * @brief This will retrieve the most recent message from the message retriever.
     * 
     */
    virtual void getNewMessage() = 0;

};

#endif