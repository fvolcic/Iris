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
#include "printer.h"

#ifndef MESSAGESYSTEM_CPP
#define MESSAGESYSTEM_CPP

bool MessageSystem::startMessageSystem(MessageSystem::messageSystemConfig *config)
{
    Thread::thread_config threadconfig{};
    threadconfig.task = getTaskEntry(_run);
    threadconfig.stackDepth = 10000; 
    PRINT("CREATING THREAD\n");
    MessageSystem::MessageThreadHandle = Thread::create_thread(&threadconfig);
    return true; 
}

// FIXME Kill message system causing core dump and program to reset
// Below is an copy and paste of the core dump when this function was attempted to be called.
/*
Guru Meditation Error: Core  0 panic'ed (LoadStoreError). Exception was unhandled.
Core 0 register dump:
PC      : 0x40092b05  PS      : 0x00060233  A0      : 0x80091605  A1      : 0x3ffca310  
A2      : 0x3ffc445c  A3      : 0x3ffba54c  A4      : 0x00000001  A5      : 0x00000001  
A6      : 0x00060220  A7      : 0x00000000  A8      : 0x3f401480  A9      : 0x3f401480  
A10     : 0x00000000  A11     : 0x00000000  A12     : 0x3ffbd80c  A13     : 0x00000000  
A14     : 0x00000000  A15     : 0x00008000  SAR     : 0x00000010  EXCCAUSE: 0x00000003  
EXCVADDR: 0x3f401488  LBEG    : 0x400014fd  LEND    : 0x4000150d  LCOUNT  : 0xfffffff9  

ELF file SHA256: 0000000000000000

Backtrace: 0x40092b05:0x3ffca310 0x40091602:0x3ffca330 0x400d3805:0x3ffca350 0x400d2f54:0x3ffca370 0x400d2a12:0x3ffca390 0x400d25a7:0x3ffca3d0 0x400d2f03:0x3ffca450 0x400901d2:0x3ffca480

Rebooting...
*/
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
            delayTask(1000); // <------ FIX THIS !!!!!!!!!!!
            continue;
        }
        else
        {
            PRINT("\n\nNEW MESSAGE!!\n\n");
            DecoderSystem::decode_execute(msg);
        }
    }
}

Thread::thread_handle MessageSystem::MessageThreadHandle;

#endif