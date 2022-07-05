/**
 * @file LightEngine.h
 *
 * @brief The light engine powers the lighting interface. It allows
 *        the device to control light strips
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "LEDColor.h"
#include "LEDColorSequence.h"

#ifndef LIGHTENGINE_H
#define LIGHTENGINE_H

struct LightEngineConfig{
    int led_count;
};

class LightEngine
{

public:

    LightEngine(LightEngineConfig & config); 

    /**
     * @brief Write an array of colors to the LED strip 
     
     * 
     * @param colors 
     */
    void add_layer(LEDColorSequence & sequence); 

    /**
     * @brief Write the colors to the attached hardware 
     * 
     */
    void hardware_write(); 

private:

    LED_color * colors; 

};

#endif
