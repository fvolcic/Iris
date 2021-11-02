/**
 * @file bluetooth_reciever.h
 * 
 * @brief 
 * @version 0.1
 * @date 2021-08-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "MessageSystem/messageretriever.h"
#include "BluetoothSerial.h"

#ifndef BT_H
#define BT_H

class BlueToothRetriever : public MessageRetrieverBase {

public:

    virtual void setupRetriever() override;
    virtual void updateRetriever() override; 

private:

    BluetoothSerial SerialBT;

};

#endif
