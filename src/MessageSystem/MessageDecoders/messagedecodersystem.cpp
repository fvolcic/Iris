/**
 * @file messagedecodersystem.cpp
 * 
 * @brief Message decoder implementation
 * @version 0.1
 * @date 2021-08-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "ArduinoJson.h"
#include "MessageSystem/message.h"
#include "MessageSystem/MessageDecoders/messagedecoderbase.h"
#include "MessageSystem/MessageDecoders/messagedecodersystem.h"

// Decoders below
#include "MessageSystem/MessageDecoders/messagedecodertest.h"

#ifndef MESSAGEDECODERSYS_CPP
#define MESSAGEDECODERSYS_CPP

bool DecoderSystem::decode_execute(Message *msg)
{

    DeserializationError err = deserializeJson(DecoderSystem::jsonObj, msg->begin());

    if (err != DeserializationError::Ok)
    {
        msg->DestroyMessage();
        return false;
    }

    const char *val = jsonObj["type"];

    if (!val)
        return false;

    for (unsigned int i = 0; i < DecoderSystem::num_decoders; ++i)
    {

        if (DecoderSystem::decoders[i]->compare(val))
        {
            return DecoderSystem::decoders[i]->decode(& jsonObj);
        }
    }

    return false;
}

StaticJsonDocument<MAX_MESSAGE_LENGTH> DecoderSystem::jsonObj;

// Decoders \/
ExampleDecoder DecoderSystem::exampledecoder;

// Storage for the different internal message decoder classes
unsigned int DecoderSystem::num_decoders = 1;
MessageDecoderBase * DecoderSystem::decoders[] = {&DecoderSystem::exampledecoder}; 

#endif
