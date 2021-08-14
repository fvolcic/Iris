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

#include "messagedecoderbase.h"

class ExampleDecoder : public MessageDecoderBase {

public:

    /**
     * @brief Get the key object
     * 
     * @return const char const* 
     */
    virtual const char const * get_key() override; 

    /**
     * @brief Decode the message and execute needed operations.
     * 
     * @return true 
     * @return false 
     */
    virtual bool decode(JsonDocument & doc) override; 

private:

    static const char msgKey[]; 
};

