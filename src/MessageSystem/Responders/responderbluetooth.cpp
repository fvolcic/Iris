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

#include "Utils/bluetooth_tools.h"
#include "BluetoothSerial.h"
#include "MessageSystem/Responders/responderbluetooth.h"
#include "Utils/printer.h"

/**
 * @brief Construct a new Bluetooth Responder:: Bluetooth Responder object
 * 
 * @bug
 */
BluetoothResponder::BluetoothResponder()
{
    // FIXME When this is added to the code, the code no longer boots. There is a (RTCWDT_RTC_RESET), 
    // This is due to a watchdog timer error. The reason behind this is not entirely clear, but I am 
    // Guessing that it has to do with multiple bluetooth initializations happening. The bluetooth responder
    // Is created as a global variable, and that may be part of the problem. Not 100% sure though. 

    // Bluetooth::initializeBluetooth();
}

BluetoothResponder::~BluetoothResponder() {}

ResponderBase::ResponseError BluetoothResponder::sendDataUntilByte(const char *data, char endByte, int length)
{
    if (Bluetooth::BluetoothSephamore != NULL)
    {
        if (xSemaphoreTake(Bluetooth::BluetoothSephamore, (TickType_t)30 / 10.0) == pdTRUE)
        {
            
            if (length == -1)
                length = __INT_MAX__;

            for (char *i = (char *)data; *i != endByte && (i - data) < length; ++i)
            {
                Bluetooth::SerialBT.print(*i);
            }
            xSemaphoreGive(Bluetooth::BluetoothSephamore);
        }
    }

    return ResponderBase::ResponseError::OK;
}

ResponderBase::ResponseError BluetoothResponder::sendDataUntilLength(const char *data, unsigned int length)
{

    if (Bluetooth::BluetoothSephamore != NULL)
    {

        if (xSemaphoreTake(Bluetooth::BluetoothSephamore, (TickType_t)30 / 10.0) == pdTRUE)
        {
            for (unsigned int i = 0; i < length; ++i)
            {
                Bluetooth::SerialBT.print(data[i]);
            }
            xSemaphoreGive(Bluetooth::BluetoothSephamore);
        }
    }
    return ResponderBase::ResponseError::OK;
}

ResponderBase::ResponseError BluetoothResponder::enable_component()
{
    PRINT("BluetoothResponder Has been enabled!\n");
    return ResponderBase::ResponseError::OK;
}
