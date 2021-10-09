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
#include "bluetooth_tools.h"
#include "special_includes.h"

//getFreeRTOSHeader(semphr.h)

//#include "semphr.h"
#include "/home/franklin/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/freertos/freertos/semphr.h"
//#include <semphr.h>

void BlueToothRetriever::setupRetriever(){
    PRINT("Starting Bluetooth\n");
    Bluetooth::initializeBluetooth();
   // BlueToothRetriever::SerialBT = BluetoothSerial(); 
   // SerialBT.begin();
    PRINT("Bluetooth started\n");
}

void BlueToothRetriever::updateRetriever(){
    if( Bluetooth::BluetoothSephamore != NULL ){

        //FIXME This semaphore shit does not work.. 
        PRINT("Retriever Trying to take semaphore\n");
        if( xSemaphoreTake( Bluetooth::BluetoothSephamore, (TickType_t) 30 / 10.0) == pdTRUE ){
            PRINT("semaphore taken\n");
            if(Bluetooth::SerialBT.available()){
                Message * messageBuffer = this->getMessageBuffer();
                Bluetooth::SerialBT.readBytesUntil(Utils::LEDSerial::finalSerialByte, (uint8_t *)( messageBuffer->begin()), MAX_MESSAGE_LENGTH); // hack lmfao
                this->enqueue_message(messageBuffer); 
            }
            
            xSemaphoreGive(Bluetooth::BluetoothSephamore);
            PRINT("semaphore given");
        }

    }

}
