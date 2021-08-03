/**
 * @file messagesystem.cpp
 * 
 * @brief File containing information regaurding the message system implmenentaiton
 * @version 0.1
 * @date 2021-08-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "messagesystem.h"
#include "thread.h"

bool MessageSystem::startMessageSystem(MessageSystem::messageSystemConfig *config){
    Thread::thread_config threadconfig{};
    threadconfig.task = getTaskEntry(_run); 
    MessageSystem::MessageThreadHandle = Thread::create_thread(& threadconfig); 
}

bool MessageSystem::killMessageSystem(){
    Thread::delete_task(MessageSystem::MessageThreadHandle);
    return true; // kinda just assume this always works lmao
}