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
#include "utils.h"

#ifdef VERBOSE
#define PRINTER_SETUP()\
(Utils::LEDSerial::initializeSerial())
#endif

#ifndef VERBOSE
#define PRINTER_SETUP() ()
#endif

#ifdef VERBOSE
#define PRINT(str)\
    (Utils::LEDSerial::print( (str) ))
#endif

#ifndef VERBOSE
#define PRINT(str) ()
#endif
