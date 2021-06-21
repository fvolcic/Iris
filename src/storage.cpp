/**
 * @file storage.cpp
 * 
 * @brief Contains definitions of storage functions.
 * @version 0.1
 * @date 2021-06-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <Crypto.h>
#include <AES.h>

#include "storage.h"
#include "SPIFFS.h"

bool Filesystem::launch(){

    // If the filesystem has already been launched,
    // then return true. 
    if(Filesystem::is_mounted())
        return true; 

    //Attempt to mount to fs. 
    //If mounting fails, then return false to indicate failure.
    if(!SPIFFS.begin(true))
        return false; 

    char checkfile[] = "/check"; 
    bool check = SPIFFS.exists(checkfile); 

    //Check if the file exists. 
    if(!check){
        //return false if there was a formatting failure.
        if(!SPIFFS.format()){
            return false; 
        }
        //Create the check file in SPIFFS
        char mode = 'w'; 
        if(!SPIFFS.open(checkfile, & mode)){
            return false; 
        }
    }

    Filesystem::launch_success = true;
    return true; 
}

bool Filesystem::format_filesystem(){
    if(!Filesystem::is_mounted())
        return false; 
    
    return SPIFFS.format(); 
}

bool Filesystem::is_mounted(){
    return Filesystem::launch_success; 
}

char * Filesystem::get_data(char * key){

    if(!Filesystem::is_mounted())
        return nullptr; 

    //Return nothing if file does not exist. 
    if(!SPIFFS.exists(key))
        return nullptr;

    File file = SPIFFS.open(key); 

    if(!file)
        return nullptr; 

    size_t filesize = file.size(); 
    char * fileBuffer = new char[filesize];

    file.readBytes(fileBuffer, filesize); 

    file.close();  
    return fileBuffer; 
}

bool Filesystem::store_data(char * key, char * data, bool strict){

    // If there was an error mounting the filesystem 
    if(!Filesystem::is_mounted())
        return false; 

    // If the data already exists and we are in strict mode.
    if(strict && SPIFFS.exists(key))
        return false; 

    const char mode = 'w'; 
    File file = SPIFFS.open(key, & mode); 

    // Otherwise, write all datum into memory. 
    for(char * begin = data; *begin;++begin)
        file.write(*begin); 
    file.write('\0'); 

    file.close(); 
    return true; 
}

bool Filesystem::file_exists(char * filename){
    if(!is_mounted())
        return false; 
    return SPIFFS.exists(filename); 
}

bool delete_file(char * filename, bool strict=false){

    if(!Filesystem::is_mounted())
        return false; 

    if(strict && !Filesystem::file_exists(filename))
        return false; 
    
    if(!Filesystem::file_exists(filename))
        return true; 
    
    return SPIFFS.remove(filename); 

}

//TODO::------------------------------------------------------------------------------------
//Must actually implement the excrypted data storage methods. This currently just stores data normally,
//but should really use an encrypted key that is stored in the program binary. 
bool Filesystem::store_encrypted_data(char * key, char * data, bool strict, uint8_t * secret_key){
    return Filesystem::store_data(key, data, strict); 
}

char * Filesystem::get_encrypted_data(char * key, uint8_t * secret_key){
    return Filesystem::get_data(key); 
}