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

    ResponderBase();
    virtual ~ResponderBase();

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

    /**
     * @brief Send a message with the responder.
     * 
     * @param message 
     * @return ResponseError 
     */
    virtual ResponseError send(char * message) = 0;

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
     * @note ex.) Ensuring that bluetooth is turned on when the bluetooth responder is enableds
     * 
     * @return ResponseError 
     */
    virtual ResponseError enable_component();

private:

    bool enabled = false;

};