/**
 * @file respondersystem.cpp
 * 
 * @brief Implementation of respondersystem.h
 * @version 0.1
 * @date 2021-08-21
 * 
 * @copyright Copyright (c) 2021
 * 
 * 
 */

//FIXME Actually test this file and functions

#include "respondersystem.h"
#include "responderbase.h"

// This has a very specific ordering.
// Each element of the Responder_Pointers must align in the same place as there numeric 
// value in the enum class that defines all the responders.
// This array also will always have ENUM_SIZE(responders) number of elts 
ResponderBase * Respond::Responder_Pointers[] = {};


Respond::ResponderError Respond::enableAllResponders(){

    unsigned int index_shift = 0;
    Respond::num_enabled_responders = 0;
    Respond::ResponderError returnErr = Respond::ResponderError::OK;

    for(unsigned int i = 0; i < num_responders; ++i){
        
        ResponderBase::ResponseError err = Responder_Pointers[i]->enable();
        
        // Success
        if( err == ResponderBase::ResponseError::OK ||
            err == ResponderBase::ResponseError::AlreadyEnabed ){
                Respond::enabledResponders[i - index_shift] = static_cast<Respond::Responders>(i);
                ++Respond::num_enabled_responders;
        }
        
        // Failure
        else
        {
            returnErr = Respond::ResponderError::FailedToEnableSome;
            ++index_shift;
        }

    }

    return returnErr; 
}

Respond::ResponderError Respond::disableAllResponders(){

    Respond::ResponderError returnError = Respond::ResponderError::OK;

    int index = 0;

    for(int i = 0; i < Respond::num_enabled_responders; ++i){

        while(Respond::enabledResponders[i] != static_cast<Respond::Responders>(index)){
            ++index;
        }

        ResponderBase::ResponseError err = Respond::Responder_Pointers[index]->disable();

        if(err != ResponderBase::ResponseError::OK or
            err != ResponderBase::ResponseError::AlreadyDisabled or
            err != ResponderBase::ResponseError::ForceDisabled){
                returnError = Respond::ResponderError::FailedToDisableSome;
        }

    }

    return returnError; 

}

Respond::ResponderError Respond::disableResponder(Respond::Responders responder){
    int index = 0;

    while( Respond::enabledResponders[index] != responder){
        ++index;

        if(index >= num_enabled_responders) // Already disabled
            return Respond::ResponderError::OK;
    }

    --num_enabled_responders; // Assume that the responder is disabled, even on disable failure.
                              // Even if it doesn't disable, it will no longer respond with responder.

    for(int i = index; i < num_enabled_responders - 1; ++i){
        Respond::enabledResponders[index] = Respond::enabledResponders[index + 1];
    }

    ResponderBase::ResponseError err = Respond::Responder_Pointers[static_cast<unsigned int>(responder)]->disable();

     if(err != ResponderBase::ResponseError::OK or
            err != ResponderBase::ResponseError::AlreadyDisabled or
            err != ResponderBase::ResponseError::ForceDisabled){
                return Respond::ResponderError::FailedToDisable;
        }

    return Respond::ResponderError::OK;

}

Respond::ResponderError Respond::enableReponder(Respond::Responders responder){
    
    // check to ensure that the responder is not already in use.
    for(int i = 0; i < num_enabled_responders; ++i){
        if( enabledResponders[i] == responder ){
            return ResponderError::AlreadyEnabled; 
        }
    }

    ResponderBase::ResponseError err = Respond::Responder_Pointers[static_cast<unsigned int>(responder)]->enable();

    if( err != ResponderBase::ResponseError::OK or
        err != ResponderBase::ResponseError::AlreadyEnabed
        ){
            return Respond::ResponderError::FailedToEnable;
        }
    
    Respond::enabledResponders[num_enabled_responders] = responder;
    ++num_enabled_responders;
    return Respond::ResponderError::OK; 

}

Respond::ResponderError Respond::sendDataUntilByte(const char * data, char endByte, int length){
    ResponderBase::ResponseError err = ResponderBase::ResponseError::OK;
    for(unsigned int i = 0; i < num_enabled_responders; ++i){
        err = Responder_Pointers[ static_cast<unsigned int>(enabledResponders[i]) ]->sendDataUntilByte(data, endByte, length); 
    }
    if(err == ResponderBase::ResponseError::OK)
        return Respond::ResponderError::OK;
    else
        return Respond::ResponderError::UnknownError;
}

Respond::ResponderError Respond::sendDataUntilLength(const char * data, int length){
    ResponderBase::ResponseError err = ResponderBase::ResponseError::OK;
    for(unsigned int i = 0; i < num_enabled_responders; ++i){
        err = Responder_Pointers[ static_cast<unsigned int>(enabledResponders[i]) ]->sendDataUntilLength(data, length);
    }
    if(err == ResponderBase::ResponseError::OK)
        return Respond::ResponderError::OK;
    else
        return Respond::ResponderError::UnknownError;
}
