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
#include "BTAddress.h"
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <Arduino.h>

#define SERVICE_UUID "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" // UART service UUID
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

// Initializations of some of the global variables
bool Bluetooth::bluetooth_initialized = false;
SemaphoreHandle_t Bluetooth::BluetoothSephamore = NULL;
bool Bluetooth::deviceConnected = false;
BLEServer *Bluetooth::pServer = NULL;
BLECharacteristic *Bluetooth::pTxCharacteristic = NULL;
ledstd::RingBuffer<String, 6> Bluetooth::rx_buffer;

BLEUUID Bluetooth::service_uuid(SERVICE_UUID);
BLEUUID Bluetooth::characteristic_uuid_rx(CHARACTERISTIC_UUID_RX);
BLEUUID Bluetooth::characteristic_uuid_tx(CHARACTERISTIC_UUID_TX);

class MyServerCallbacks : public BLEServerCallbacks
{
    void onConnect(BLEServer *pServer)
    {
        Serial.write("Connected\n");
        Bluetooth::deviceConnected = true;
    };

    void onDisconnect(BLEServer *pServer)
    {
        Serial.write("Disconnected\n");
        Bluetooth::pServer->startAdvertising(); // restart advertising
        Bluetooth::deviceConnected = false;
    }
};

class MyCallbacks : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic *pCharacteristic)
    {
        std::string rxValue = pCharacteristic->getValue();

        if (rxValue.length() > 0)
        {
            Serial.println("*********");
            Serial.print("Received Value: ");
            for (int i = 0; i < rxValue.length(); i++)
                Serial.print(rxValue[i]);

            Serial.println();
            Serial.println("*********");

            Bluetooth::rx_buffer.push(String(rxValue.c_str()));
        }
    }
};

void Bluetooth::initializeBluetooth()
{

    Serial.println("1");

    if (bluetooth_initialized)
        return;

    bluetooth_initialized = true;

    // vSemaphoreCreateBinary(BluetoothSephamore); <-- Depreciated Semaphore creation tool
    BluetoothSephamore = xSemaphoreCreateBinary();

    // Create the BLE Device
    BLEDevice::init("Iris Lights");

    Serial.println("2");

    Bluetooth::pServer = BLEDevice::createServer();
    Bluetooth::pServer->setCallbacks(new MyServerCallbacks());

    Serial.println("3");

    BLEService *pService = Bluetooth::pServer->createService(Bluetooth::service_uuid);

    Serial.println("3.1");

    Bluetooth::pTxCharacteristic = pService->createCharacteristic(
        Bluetooth::characteristic_uuid_tx,
        BLECharacteristic::PROPERTY_NOTIFY);

    Serial.println("3.2");

    Bluetooth::pTxCharacteristic->addDescriptor(new BLE2902());

    Serial.println("4");

    BLECharacteristic *pRxCharacteristic = pService->createCharacteristic(
        CHARACTERISTIC_UUID_RX,
        BLECharacteristic::PROPERTY_WRITE);

    pRxCharacteristic->setCallbacks(new MyCallbacks());

    Serial.println("5");

    pService->start();
    pServer->getAdvertising()->addServiceUUID(SERVICE_UUID);
    pServer->getAdvertising()->start();

    Serial.println("Bluetooth Ready and Advertising");

    xSemaphoreGive(BluetoothSephamore); // Required to give semaphore before it can be taken by any threads
}

void Bluetooth::deinitBluetooth()
{
}

bool Bluetooth::bluetoothReady()
{
    return bluetooth_initialized;
}

bool Bluetooth::hasNextMessage()
{
    return Bluetooth::rx_buffer.size() != 0;
}

String Bluetooth::getNextMessage()
{
    auto msg = Bluetooth::rx_buffer.next();
    Bluetooth::rx_buffer.pop();
    return msg;
}