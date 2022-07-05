/**
 * @file LEDColorSequence.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "LEDColor.h"

#ifndef LEDCOLORSEQUENCE_H
#define LEDCOLORSEQUENCE_H

struct LEDColorSequenceConfig{

    int led_count; 

};

class LEDColorSequence
{

public:

    LEDColorSequence() = delete;
    LEDColorSequence(LEDColorSequenceConfig * config); 

    /**
     * @brief Get the LED_color at the specified index 
     * 
     * @param index 
     * @return LED_color& 
     */
    LED_color & operator[](int index);
    
    /**
     * @brief Return a pointer to the internal colors array 
     *        that this LEDColorSequence represents 
     * 
     * @return LED_color* 
     */
    inline LED_color * data(){
        return colors_internal; 
    } 
    
    /**
     * @brief Get the number of colors in the sequence. 
     * 
     * @return int 
     */
    inline int get_num_colors(){
        return num_colors; 
    }

private:

    int num_colors; // How many colors does this color sequence represent. 
    LED_color * colors_internal; // The internal array holding the colors data. 
    

};

#endif
