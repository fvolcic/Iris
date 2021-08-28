/**
 * @file bluetooth_reciever.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "bluetooth_reciever.h"
#include "BluetoothSerial.h"
#include "printer.h"

void BlueToothRetriever::setupRetriever(){
    PRINT("Starting Bluetooth\n");
    BlueToothRetriever::SerialBT = BluetoothSerial(); 
    SerialBT.begin();
    PRINT("Bluetooth started\n");
}

void BlueToothRetriever::updateRetriever(){
    // PRINT("Running Update BT\n");
    if(BlueToothRetriever::SerialBT.available()){
        Message * messageBuffer = this->getMessageBuffer();
        SerialBT.readBytesUntil(Utils::LEDSerial::finalSerialByte, (uint8_t *)( messageBuffer->begin()), MAX_MESSAGE_LENGTH); // hack lmfao
        this->enqueue_message(messageBuffer); 
    }
}
