/**
 * @file messagedecoderbase.cpp
 * 
 * @brief 
 * @version 0.1
 * @date 2021-07-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "messagedecoderbase.h"
#include "utils.h"

bool MessageDecoder::compare(const char * str){
    return Utils::Compare::cstrcmp(this->get_key() , str); 
}