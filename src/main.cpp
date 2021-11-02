/**
 * @file main.cpp
 * 
 * @brief This file contains the entry point for the led controller
 * @version 0.1
 * @date 2021-06-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <Arduino.h>

#include "System/storage.h"
#include "Utils/printer.h"
#include "MessageSystem/messagesystem.h"

void setup() {

  PRINTER_SETUP();
  PRINT("Welcome to Iris\n");
  PRINT("Debug Mode::True\n");


  PRINT("Starting the message system\n");
  MessageSystem::startMessageSystem({}); 

}

//Delete this execution thread.
void loop() {vTaskDelete(NULL);}
