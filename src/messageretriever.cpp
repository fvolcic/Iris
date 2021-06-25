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

#ifndef MESSAGERETRIEVER_CPP
#define MESSAGERETRIEVER_CPP

MessageRetrieverBase::Message * MessageRetrieverBase::getMessageBuffer(){

    MessageRetrieverBase::Message * messageBuffer;

    // This is where we determine what kind of buffer we need.
    // We will always attempt to use the internal static buffer if it is free,
    // but in the case that it is not available, we will use a dynmic buffer. 
    if(staticbufferAvailable){
        staticbufferAvailable = false; 
        messageBuffer = new MessageRetrieverBase::Message(this->messageBuffer, 
                                                    MessageRetrieverBase::Message::MessageType::StaticMessage,
                                                    & staticbufferAvailable);
    }else{
        messageBuffer = new MessageRetrieverBase::Message(MessageRetrieverBase::getDynamicBuffer(),
                                                    MessageRetrieverBase::Message::MessageType::DynamicMessage,
                                                    & throwaway);
    }

    return messageBuffer; 
}

void MessageRetrieverBase::enqueue_message(Message * msgPtr){
    messages.push(msgPtr); 
}

bool MessageRetrieverBase::isMessageAvailable(){
    return messages.size() != 0;
}

MessageRetrieverBase::Message * MessageRetrieverBase::getNewMessage(){
    MessageRetrieverBase::Message * tmpMsg = messages.front(); 
    messages.pop(); 
    return tmpMsg; 
}

// Below definitions are for the internal message class. ------------------------------------------

MessageRetrieverBase::Message:: Message(char * message, MessageType type, bool * flag)
: buffer(message), msgType(type) ,finishedWriteFlag(flag) 
{}

char * MessageRetrieverBase::Message::operator()(){
    return buffer; 
}

void MessageRetrieverBase::Message::DestroyMessage(){
    if(!messageAlive)
        return;
    if(msgType == MessageRetrieverBase::Message::MessageType::DynamicMessage)
        delete buffer;
    (*finishedWriteFlag) = true; 
    messageAlive = false; 
}

char * MessageRetrieverBase::Message::begin(){
    return buffer; 
}

char * MessageRetrieverBase::Message::end(){ 
    return buffer + MAX_MESSAGE_LENGTH; 
}

#endif