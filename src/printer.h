/**
 * @file printer.h
 * 
 * @brief Defines extra printing functionality for printing via the serial ports.
 * @version 0.1
 * @date 2021-06-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "globals.h"

#ifdef VERBOSE
#define PRINTER_SETUP() \ 
    (Serial.begin(BAUD))
#endif

#ifndef VERBOSE
#define PRINTER_SETUP() ()
#endif

#ifdef VERBOSE
#define PRINT(str) \
    (Serial.println( (str) ))
#endif

#ifndef VERBOSE
#define PRINT(str) ()
#endif
