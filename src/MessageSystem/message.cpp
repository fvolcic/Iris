/**
 * @file message.cpp
 * 
 * @brief implementation of the message.h struct.
 * @version 0.1
 * @date 2021-06-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "MessageSystem/message.h"
#include "Utils/globals.h"

Message::Message(char *message, MessageType type, bool *flag)
    : buffer(message), msgType(type), messageBufferInUse(flag)
{
}

char *Message::operator()()
{
    return buffer;
}

void Message::DestroyMessage()
{
    if (!messageAlive)
        return;
    if (msgType == Message::MessageType::DynamicMessage)
        delete buffer;
    (*messageBufferInUse) = true;
    messageAlive = false;
}

char *Message::begin()
{
    return buffer;
}

char *Message::end()
{
    return buffer + MAX_MESSAGE_LENGTH;
}
