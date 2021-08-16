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
#include "messagemanager.h"
#include "thread.h"
#include "utils.h"
#include "messagedecodersystem.h"

#ifndef MESSAGESYSTEM_CPP
#define MESSAGESYSTEM_CPP

bool MessageSystem::startMessageSystem(MessageSystem::messageSystemConfig *config)
{
    Thread::thread_config threadconfig{};
    threadconfig.task = getTaskEntry(_run);
    MessageSystem::MessageThreadHandle = Thread::create_thread(&threadconfig);
    return true; 
}

bool MessageSystem::killMessageSystem()
{
    Thread::delete_task(&MessageSystem::MessageThreadHandle);
    return true;
}

void MessageSystem::_run(task_param_requirements)
{
    MessageManager manager; // The funnel for messages from the different message sources
    while (true)
    {
        Message *msg = manager.getNewMessage();
        if (msg == nullptr)
        {
            /**
             * @todo Actually implement a time that we need to wait.
             * 
             */
            delayTask(100); // <------ FIX THIS !!!!!!!!!!!
            continue;
        }
        else
        {
            DecoderSystem::decode_execute(msg);
        }
    }
}

Thread::thread_handle MessageSystem::MessageThreadHandle;

#endif