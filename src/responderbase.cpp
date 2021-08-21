/**
 * @file responderbase.cpp
 * 
 * @brief implementation of responderbase.h
 * @version 0.1
 * @date 2021-08-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "responderbase.h"

ResponderBase::ResponderBase(){}
ResponderBase::~ResponderBase(){}

ResponderBase::ResponseError ResponderBase::enable(){
    if(enabled)
        return ResponseError::AlreadyEnabed;
    ResponseError error = this->enable_component();

    if(error == ResponseError::OK){
        enabled = true;
        return ResponseError::OK;
    }else{
        return error;
    }
}

ResponderBase::ResponseError ResponderBase::disable(){
    if(!enabled)
        return ResponseError::AlreadyDisabled;
    
    ResponseError error = this->disable_component();

    if(error == ResponseError::OK){
        enabled = false;
        return ResponseError::OK;
    }else{
        return error;
    }
}

ResponderBase::ResponseError ResponderBase::disable_component(){
    return ResponderBase::ResponseError::OK;
}

ResponderBase::ResponseError ResponderBase::enable_component(){
    return ResponderBase::ResponseError::OK;
}