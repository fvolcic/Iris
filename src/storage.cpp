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


#include "storage.h"
#include "SPIFFS.h"
#include "mbedtls/aes.h"
#include <cmath>

bool Filesystem::launch_success = false; 

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
        static const char mode = 'w'; 
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

char * Filesystem::get_data(const char * key){

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

bool Filesystem::store_data(const char * key, char * data, bool strict){

    // If there was an error mounting the filesystem 
    if(!Filesystem::is_mounted())
        return false; 

    // If the data already exists and we are in strict mode.
    if(strict && SPIFFS.exists(key))
        return false; 

    static const char mode = 'w'; 
    File file = SPIFFS.open(key, & mode); 

    // Otherwise, write all datum into memory. 
    for(char * begin = data; *begin;++begin)
        file.write(*begin); 
    file.write('\0'); 

    file.close(); 
    return true; 
}

bool Filesystem::file_exists(const char * filename){
    if(!is_mounted())
        return false; 
    return SPIFFS.exists(filename); 
}

bool Filesystem::delete_file(const char * filename, bool strict){

    if(!Filesystem::is_mounted())
        return false; 

    if(strict && !Filesystem::file_exists(filename))
        return false; 
    
    if(!Filesystem::file_exists(filename))
        return true; 
    
    return SPIFFS.remove(filename); 

}

//TODO::------------------------------------------------------------------------------------
//Must actually implement the encrypted data storage methods. This currently just stores data normally,
//but should really use an encrypted key that is stored in the program binary. 

//FIXME: These simply do not work at all... fuck

bool Filesystem::store_encrypted_block(const char * filename, const char * datum, const unsigned char * key){
    if(!is_mounted())
        return false; 

    mbedtls_aes_context aes; 
    unsigned int datum_size_t = 0;
    char * datum_index = (char  *)datum;
    
    while(*datum_index){
        ++datum_size_t;
        ++datum_index;
    }

    unsigned int num_blocks = ceil( (double) datum_size_t / 16.0 ); // determine the number of needed blocks

    unsigned char * output_buffer = new u_char[num_blocks * 16 + 1]; // output buffer for storing encrypted data

    unsigned char testkey[] = "bcdefghijklmnop"; // <---- REMOVE THIS AND USE ACTUAL KEY

    mbedtls_aes_init( &aes );
    mbedtls_aes_setkey_enc( &aes, testkey, 128);
    
    unsigned char* index = (unsigned char *)datum;

    for(int i = 0; i < num_blocks; ++i){
        mbedtls_aes_crypt_ecb( &aes, ESP_AES_ENCRYPT, index + (i * 16), output_buffer + (i * 16));
    }
    
    output_buffer[num_blocks*16+1] = '\0';

    return Filesystem::store_data(filename, (char *) output_buffer);
}

char * Filesystem::get_encrypted_block(const char * filename, const unsigned char * key){

    if(!is_mounted())
        return nullptr; 

    static const char mode = 'w'; 
    File file = SPIFFS.open(filename, & mode); 

    unsigned char * encrypted_file = (unsigned char *) Filesystem::get_data(filename);

    int num_blocks = ceil ( file.size() / 16.0 );

    unsigned char * output_buffer = new unsigned char[num_blocks * 16];

    mbedtls_aes_context aes; 
    unsigned char testkey[] = "bcdefghijklmnop"; // <---- REMOVE THIS AND USE ACTUAL KEY

    mbedtls_aes_init( &aes );
    mbedtls_aes_setkey_enc( &aes, testkey, 128);


    for(int i = 0; i < num_blocks; ++i){
        mbedtls_aes_crypt_ecb( &aes , ESP_AES_DECRYPT, encrypted_file + (i * 16), output_buffer + (i * 16));
    }

    delete[] encrypted_file;
    return (char *)output_buffer;
}