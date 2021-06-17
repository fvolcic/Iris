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

#include "network.h"
#include "storage.h"
#include "printer.h"

void setup() {
  PRINTER_SETUP();
  PRINT("LED Lights v3.");
  //Network::connect(); 

  Serial.begin(115200); 
  Serial.println("Launching...");
  Serial.println(Filesystem::launch()); 
  Serial.println("Launched..."); 
  //Serial.println(Filesystem::store_data("/SSID", "NETGEAR24\0")); 
  //Serial.println(Filesystem::store_data("/PASS", "littlecartoon561\0")); 
  char * filePtr = Filesystem::get_data("/SSID");
  Serial.println("Outputting result\n"); 
  for(auto begin = filePtr; *begin; ++begin){
    Serial.print((char)*begin); 
  }
  delete filePtr; 
  Serial.println(); 
  filePtr = Filesystem::get_data("/PASS");
  for(auto begin = filePtr; *begin; ++begin){
    Serial.print((char)*begin); 
  }


}

//Delete this execution thread.
void loop() {vTaskDelete(NULL);}