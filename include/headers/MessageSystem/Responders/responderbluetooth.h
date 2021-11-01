/**
 * @file responderbluetooth.h
 * 
 * @brief Responder for the bluetooth com channel
 * @version 0.1
 * @date 2021-08-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "responderbase.h"

class BluetoothResponder : public ResponderBase {

public:

    BluetoothResponder();
    ~BluetoothResponder();

    virtual ResponseError sendDataUntilByte(const char * data, char endByte, int length = -1);

    virtual ResponseError sendDataUntilLength(const char * data, unsigned int length);

protected:
virtual ResponseError enable_component();   


}; 