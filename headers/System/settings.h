/**
 * @file settings.h
 * 
 * @brief Contains all information regaurding system settings that are used throughout the program.
 * @version 0.1
 * @date 2021-07-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SETTINGS_H
#define SETTIGNS_H

/**
 * @brief Namespace representing all different settings locations.
 * 
 */
namespace Settings{

    namespace MainThread{

        namespace LED{
            unsigned int led_brightness; // The current brightness level of the led lights
            unsigned int led_brightness_lower_bound; // The lower bound of the led lights brightness
            unsigned int led_brightness_upper_bound; // The upper bound of the led lights brightness

            unsigned int number_leds; // The number of leds on the led strip.

            bool _InitializeLEDSettings();
        };

    };

    namespace network{
        namespace WIFI{
            bool network_enabled; // is the system internet enabled or not?
            /**
            * @todo Change these pointers to static arrays. There is a maximum ssid size and password size that should be used to init arrays
            */
            char * SSID; // network SSID
            char * PASS; // netword PASSWORD

            bool _InitializeWifiSettings();
        };
    }; 

    namespace bluetooth
    {
        bool bluetooth_enabled;

        bool _initializeBTSettings(); 
    } // namespace bluetooth
    
    
    /**
     * @brief Enum class that tells if/what the error was
     * 
     */
    enum class SettingsInitErr {OK, UnkownError}; 

    /**
     * @brief Initialize the settigns module of the system
     * 
     * @return SettingsInitErr 
     */
    SettingsInitErr InitializeSettings(); 

};

#endif