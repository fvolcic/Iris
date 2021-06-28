/**
 * @file message.h
 * 
 * @brief This is where the message parsing happens.
 * 
 * @version 0.1
 * @date 2021-06-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief Base class for a message handler. This provides the interface for what is needed
 *        for parsing messages and extracting there contents. 
 * 
 * @tparam MsgTypes 
 */
template<enum class MsgTypes>
class MessageHandlerBase{
public:

    MessageHandler();
    ~MessageHandler(); 

    /**
     * @brief Check if a message of a given type is available. 
     * 
     * @tparam MsgTypes 
     * @tparam MsgType 
     * @return true 
     * @return false 
     */
    template<enum class MsgTypes, MsgTypes MsgType>
    bool MessageAvailable(); 

private:

};