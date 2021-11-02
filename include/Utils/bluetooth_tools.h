/**
 * @file bluetooth_tools.h
 * 
 * @brief 
 * @version 0.1
 * @date 2021-08-29
 * 
 * @note This is for SerialBluetooth.
 * // FIXME Change this to use the esp32 SPP bluetooth api.
 * // If ReactNative has a library for bluetooth serial, then
 * // We are good, if not, this will need to be changed.
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "BluetoothSerial.h"
//#include "components/freertos/include/freertos/semphr.h"
//#include "semph.h"

namespace Bluetooth{

    extern BluetoothSerial SerialBT; // The Global SerialBT object

    extern SemaphoreHandle_t BluetoothSephamore; // Sephamore for getting bluetooth 


    /**
     * @brief Initialize the bluetooth
     * 
     */
    void initializeBluetooth();
    extern bool bluetooth_initialized; // Check if bluetooth has already been initialized

    /**
     * @brief Stop the bluetooth
     * 
     */
    void deinitBluetooth();

    /**
     * @brief Check if bluetooth is ready
     * 
     * @return true 
     * @return false 
     */
    bool bluetoothReady();
};
