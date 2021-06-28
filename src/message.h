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
    bool messageAlive = true; 
    char * buffer; 
    MessageType msgType; 
    bool * finishedWriteFlag;        
    
};