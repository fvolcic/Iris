/**
 * @file network.h
 * 
 * @brief Network.h takes care of all networking and provides a simple interface for
 *          communication with the outside world.
 * 
 * @version 0.1
 * @date 2021-06-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

namespace Network{

    /**
     * @brief Details all info needed to connect to a network.
     * 
     */
    struct WIFI_INFO{
        char * SSID; // SSID of the network
        char * PASS; // PASS of the network
    };

    /**
     * @brief Connect the device to the internet. This will ensure the device stays connected.
     * If the device disconnects, this function will reconnect the device to the internet.
     * This function will return false if the device cannot connect to the internet for any reason.
     * 
     * @param WIFI_INFO -> All the needed wifi params are defined within this struct. 
     * 
     * @return true
     * @return false
     * 
     */
    bool connect(const WIFI_INFO * info); 

    /**
     * @brief Connect to the internet, and automatically get ssid and password for the connection.
     * 
     * @return true 
     * @return false 
     */
    bool connect();

    /**
     * @brief Disconnect the device from the internet. Shuts off current network connection.
     * 
     */
    void disconnect();

};