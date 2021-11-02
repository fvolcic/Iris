/**
 * @file responderbase.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef RESPONDERBASE_H
#define RESPONDERBASE_H

/**
 * @brief The responder base class
 * 
 */
class ResponderBase{

public:

    /**
     * @brief Class that represents different errors that can occur within a responder
     * 
     */
    enum class ResponseError{ OK, NotEnabled, ConnectionError, UnknownError, ForceDisabled, CannotEnable, CannotDisable, AlreadyEnabed, AlreadyDisabled };

    /**
     * @brief Construct a new Responder Base object
     * 
     */
    ResponderBase();


    // ********************************
    // *     VIRTUAL METHODS BELOW    *
    // ********************************

    /**
     * @brief Destroy the Responder Base object
     * 
     */
    virtual ~ResponderBase();

    /**
     * @brief Send a message with the responder until the endByte is reached, or a specified length.
     * 
     * @note if length = -1, then only the endByte can terminate the data being sent
     * 
     * @param message 
     * @return ResponseError 
     */
    virtual ResponseError sendDataUntilByte(const char * data, char endByte, int length = -1) = 0;

    /**
     * @brief Send data where the char array has a length equal to length
     * 
     * @param data 
     * @param length 
     * @return ResponseError 
     */
    virtual ResponseError sendDataUntilLength(const char * data, unsigned int length) = 0;

    /**
     * @brief Enable the given responder
     * 
     * @return ResponseError 
     */
    ResponseError enable();

    /**
     * @brief Disable the given responder
     * 
     * @return ResponseError 
     */
    ResponseError disable();

    /**
     * @brief Return true if the responder is currently enabled
     * 
     * @return true 
     * @return false 
     */
    bool isEnabled();

protected:

    /**
     * @brief This is needed to disable the responder and any data that needs to be changed when the responder is shut off.
     * 
     * @return ResponseError 
     */
    virtual ResponseError disable_component();

    /**
     * @brief This is needed to enable the responder and any data that needs to be changed when the responder is enabled.
     * 
     * @note ex.) Ensuring that bluetooth is turned on when the bluetooth responder is enabled
     * 
     * @return ResponseError 
     */
    virtual ResponseError enable_component();

private:

    bool enabled = false;

};

#endif
