/**
 * @file display.h
 * 
 * @brief This file contains all tools to write to and interface will the led strip.
 * @version 0.1
 * @date 2021-06-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

namespace Display{

    /**
     * @brief A color that is used for displaying to the led strip.
     * 
     */
    struct rgb_color{
        unsigned int red, green, blue;
    };

    /**
     * @brief Write the colors to the led strip.
     * 
     * @param colors 
     */
    void write(rgb_color * colors); 

};