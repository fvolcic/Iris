/**
 * @file bluetooth_tools.cpp
 * 
 * @brief implementation for bluetooth_tools.h
 * @version 0.1
 * @date 2021-08-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Utils/bluetooth_tools.h"
#include "Utils/utils.h"
#include "BluetoothSerial.h"
#include "BTAddress.h"

// Initializations of some of the global variables
bool Bluetooth::bluetooth_initialized = false;
SemaphoreHandle_t Bluetooth::BluetoothSephamore = NULL;
BluetoothSerial Bluetooth::SerialBT = BluetoothSerial();

void Bluetooth::initializeBluetooth(){

    if(bluetooth_initialized)
        return;

    bluetooth_initialized = true;

    // SerialBT = BluetoothSerial();
    SerialBT.begin();

    // vSemaphoreCreateBinary(BluetoothSephamore); <-- Depreciated Semaphore creation tool
    BluetoothSephamore = xSemaphoreCreateBinary();

    
    Utils::LEDSerial::print("BT Address: "); 
    // Utils::LEDSerial::print(bt_address.toString().c_str());

    xSemaphoreGive(BluetoothSephamore); // Required to give semaphore before it can be taken by any threads
}

void Bluetooth::deinitBluetooth(){
    SerialBT.end();
}

bool Bluetooth::bluetoothReady(){
    return bluetooth_initialized;
}
