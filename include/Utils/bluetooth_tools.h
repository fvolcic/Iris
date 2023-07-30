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

// #include "components/freertos/include/freertos/semphr.h"
// #include "semph.h"

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <Arduino.h>
#include <Utils/structures.h>

namespace Bluetooth
{

    extern SemaphoreHandle_t BluetoothSephamore; // Sephamore for getting bluetooth

    extern BLEServer *pServer;
    extern BLECharacteristic *pTxCharacteristic;
    extern bool deviceConnected;

    extern BLEUUID service_uuid;
    extern BLEUUID characteristic_uuid_rx;
    extern BLEUUID characteristic_uuid_tx;

    extern ledstd::RingBuffer<String, 6> rx_buffer;

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

    /**
     * @brief Check if a message is available to read
     *
     * @return true
     * @return false
     */
    bool hasNextMessage();

    /**
     * @brief Get the Next Message object
     *
     * @return String
     */
    String getNextMessage();


};
