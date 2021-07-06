/**
 * @file messagedecoderbase.h
 * 
 * @brief This file contains information regaurding the base class message parser.
 * @version 0.1
 * @date 2021-07-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief This decodes a specific message type. Once the message is decoded, 
 *        this class will then execute all needed operations.
 * 
 */
class MessageDecoder{

public:

    MessageDecoder(); 
    ~MessageDecoder(); 

    /**
     * @brief This will decode the actual message and then execute
     *        the needed operations. 
     * 
     * @return true 
     * @return false 
     */
    virtual bool decode() = 0;


};