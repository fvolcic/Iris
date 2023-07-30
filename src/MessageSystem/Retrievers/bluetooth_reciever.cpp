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

#include "MessageSystem/Retrievers/bluetooth_reciever.h"
#include "BluetoothSerial.h"
#include "Utils/printer.h"
#include "Utils/bluetooth_tools.h"
#include "Utils/special_includes.h"

void BlueToothRetriever::setupRetriever(){
    PRINT("Starting Bluetooth\n");
    Bluetooth::initializeBluetooth();
   // BlueToothRetriever::SerialBT = BluetoothSerial(); 
   // SerialBT.begin(); 
    PRINT("Bluetooth started\n");
}

void BlueToothRetriever::updateRetriever(){
    if( Bluetooth::BluetoothSephamore != NULL ){
        if( xSemaphoreTake( Bluetooth::BluetoothSephamore, (TickType_t) 30 / 10.0) == pdTRUE ){
            if(Bluetooth::hasNextMessage()){
                Message * messageBuffer = this->getMessageBuffer();
                auto msg = Bluetooth::getNextMessage();
                auto bufferIter = messageBuffer->begin();
                for(int i = 0; i < msg.length(); i++){
                    *bufferIter = msg[i];
                    bufferIter++;
                }
                this->enqueue_message(messageBuffer); 
            }
            
            xSemaphoreGive(Bluetooth::BluetoothSephamore);
        }

    }

}
