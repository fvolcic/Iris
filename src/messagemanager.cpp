/**
 * @file messagemanager.cpp
 * 
 * @brief Contains definitions of functions that occue in the messagemanager.h file
 * @version 0.1
 * @date 2021-06-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "messagemanager.h"

MessageManagement::MessageManager::MessageManager(){

    // Setup all the different sources. 
    for(int i = 0; i < num_sources; ++i){
        this->messageSources[i]->setupRetriever(); 
    }

}