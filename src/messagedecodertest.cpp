/**
 * @file messagedecodertest.cpp
 * 
 * @brief File contains an example message decoder.
 * @version 0.1
 * @date 2021-07-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "messagedecodertest.h"
#include "utils.h"

const char * ExampleDecoder::get_key() {
    return this->msgKey; 
}

bool ExampleDecoder::decode(JsonDocument * doc) {
    Utils::LEDSerial::initializeSerial();
    Utils::LEDSerial::print("Received New Data"); 
    Utils::LEDSerial::print(doc->data().asString()); 
}

const char ExampleDecoder::msgKey[] = "example"; 