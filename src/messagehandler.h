/**
 * @file message.h
 * 
 * @brief This is where the message parsing happens.
 * 
 * @version 0.1
 * @date 2021-06-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief Class is responsible for both JSON message parsing along with JSON data extraction.
 *        There are a variety of flags that are set depending on the different messages received.
 * 
 */
class MessageHandler{

public:

    MessageHandler(); 
    ~MessageHandler(); 

    /**
     * @brief This function parses a message. Returns false if the message was semantically invalid. True otherwise.
     * 
     * @param message 
     * @return true 
     * @return false 
     */
    bool parseMessage(char * message); 

    /**
     * @brief return true if there is a new Action ready to be displayed.
     * 
     * @return true 
     * @return false 
     */
    bool newActionAvailable();

    /**
     * @brief return true if there is a new command that needs to be executed.
     * 
     * @return true 
     * @return false 
     */
    bool newCommandAvailable();

private:
    
    bool actionAvailable = false; // Is there a new message? 
    bool commandAvailable = false; // Is there a new command?

};