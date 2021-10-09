/**
 * @file responderbluetooth.cpp
 * 
 * @brief Bluetooth responder system
 * @version 0.1
 * @date 2021-08-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "bluetooth_tools.h"
#include "BluetoothSerial.h"
#include "responderbluetooth.h"

BluetoothResponder::BluetoothResponder(){
    Bluetooth::initializeBluetooth();
}

BluetoothResponder::~BluetoothResponder(){}

ResponderBase::ResponseError BluetoothResponder::sendDataUntilByte(const char * data, char endByte, int length){

}

ResponderBase::ResponseError BluetoothResponder::enable_component(){
    
}