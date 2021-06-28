/**
 * @file messageretriever.cpp
 * 
 * @brief Defines some of the base class functionality for the classes that inhert this class to use.
 * @version 0.1
 * @date 2021-06-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "messageretriever.h"
#include "message.h"

#ifndef MESSAGERETRIEVER_CPP
#define MESSAGERETRIEVER_CPP

Message * MessageRetrieverBase::getMessageBuffer(){

    Message * messageBuffer;

    // This is where we determine what kind of buffer we need.
    // We will always attempt to use the internal static buffer if it is free,
    // but in the case that it is not available, we will use a dynmic buffer. 
    if(staticbufferAvailable){
        staticbufferAvailable = false; 
        messageBuffer = new Message(this->messageBuffer, 
                                                    Message::MessageType::StaticMessage,
                                                    & staticbufferAvailable);
    }else{
        messageBuffer = new Message(MessageRetrieverBase::getDynamicBuffer(),
                                                    Message::MessageType::DynamicMessage,
                                                    & throwaway);
    }

    return messageBuffer; 
}

void MessageRetrieverBase::enqueue_message(Message * msgPtr){
    if(messages.queue_full())
        return msgPtr->DestroyMessage(); // Do nothing with the message if the queue is full.
    
    messages.push(msgPtr); 
}

bool MessageRetrieverBase::isMessageAvailable(){
    return messages.size() != 0;
}

Message * MessageRetrieverBase::getNewMessage(){
    Message * tmpMsg = messages.next(); 
    messages.pop(); 
    return tmpMsg; 
}

// Below definitions are for the internal message class. ------------------------------------------



#endif