/**
 * @file message.cpp
 * 
 * @brief File decalares a message. This is what is used by the messageretriver.
 * @version 0.1
 * @date 2021-06-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MESSAGE_H
#define MESSAGE_H

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
     * @param flag - This is a pointer to a boolean which will we set to false upon deletion of the message.
     *             - This is needed because Message is created with both static and dynamic memory, so its important
     *             - to know when the static memory is free as that is the preffered memory to use.
     */
    Message(char * message, MessageType type, bool * flag);
    
    /**
     * @brief Returns a pointer to the buffer stored within the
     *        message struct
     * 
     * @return char* 
     */
    char * operator()(); 

    /**
     * @brief This will free all the space that the
     *        buffer was using. If there was dynmic
     *        memory in use, that memory will be destroyed.
     * 
     */
    void DestroyMessage();

    /**
     * @brief Return bidirectional iterator
     * 
     * @return char* 
     */
    char * begin();

    /**
     * @brief Return end of the internal buffer.
     * 
     * @return char* 
     */
    char * end(); 

private:
    bool messageAlive = true; // Has the message been deleted or is the message still valid.
    char * buffer; // Pointer to the internal message buffer.
    MessageType msgType; // Is the message dynamic or static in terms of buffer location
    bool * messageBufferInUse; 
    
};

#endif