/**
 * @file LEDColor.h
 *
 * @brief The LED color class defines an interface to specify
 *        the brightness of an LED pixel
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef LEDCOLOR_H
#define LEDCOLOR_H

struct LED_color
{
    LED_color();
    LED_color(char R, char G, char B);  

    char R, G, B;
    bool active = true; 
};

#endif