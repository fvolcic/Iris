/**
 * @file messagesystem.h
 * 
 * @brief This is where all the different components of the message system come together to work.
 * @version 0.1
 * @date 2021-07-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "messagemanager.h"
#include "messagedecoderbase.h"

/**
 * @brief This class outlines the entire message system. Messages are recieved, parsed, and executed,
 *        all from this class. 
 * 
 */
class MessageSystem{

        /**
         * @brief Check if there is a new message available. 
         * 
         * @return true 
         * @return false 
         */
        bool checkMessages();

    private:
        
        // The message manager class is defined in messagemanager.h
        // Essentially this is a funnel that allows all the different
        // message sources to be read together. 
        MessageManager messages(); 

};