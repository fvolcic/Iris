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
 * @brief Contains all the needed information to start and manage the message system.
 * 
 */
namespace MessageSystem{

    struct messageSystemConfig{

    };

    /**
     * @brief This begins the messaging system by starting a thread for the message system. 
     * 
     * @return true - on successful launch
     * @return false - on launch failure
     */
    bool startMessageSystem(messageSystemConfig * config); 

    /**
     * @brief Stop the message system thread.
     * 
     * @return true - on successful message system kill
     * @return false - on message system kill failure.
     */
    bool killMessageSystem();

    /**
     * @brief Run the message system in a loop for a thread.
     * 
     */
    void run();
};