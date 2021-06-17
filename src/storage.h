/**
 * @file storage.h
 * 
 * @brief This is what is used to communicate with the internal filesystem.
 * @version 0.1
 * @date 2021-06-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "globals.h"

namespace Filesystem{

    /**
     * @brief This starts the file system for reading and writing.
     *        If there was an error, this will return false. 
     * 
     * @return true 
     * @return false 
     */
    bool launch();

    /**
     * @brief Return datum from the file system. This takes the key of the data and it returns the
     *        datum stored with that key value in the filesystem.
     * 
     * @note This returns dynamically allocated memory. The file data must be deleted.
     * 
     * @param key - The key of the data
     * @return char* 
     */
    char * get_data(char * key);

    /**
     * @brief Stores a peice of data in the file system of the device. If strict is set to true,
     *        then this function will not allow you to overwrite data is there is already data stored
     *        with that key value.
     * 
     * 
     * @param key - the key of the key data pair
     * @param data - the data of the key data pair
     * @param strict - allow overwrite of existing data? 
     * @return true - on successful write
     * @return false - on failure
     */
    bool store_data(char * key, char * data, bool strict = false);

    /**
     * @brief Get encrypted datum from the file system. 
     * 
     * @note This returns dynamically allocated memory. The file data must be deleted.
     * 
     * @param key 
     * @param secret_key 
     * @return char* 
     */
    char * get_encrypted_data(char * key, uint8_t * secret_key); 

    /**
     * @brief - Store data to the filesystem that is encrypted with the secret key.
     * 
     * @param key 
     * @param data 
     * @param strict 
     * @param secret_key 
     * @return true 
     * @return false 
     */
    bool store_encrypted_data(char * key, char * data, bool strict = false, uint8_t * secret_key = 0x0); 

    /**
     * @brief Create a file in the spiffs filesystem. If strict is true and file exists, return false. 
     * 
     * @param filename 
     * @return true 
     * @return false 
     */
    bool create_file(char * filename, bool strict=false);

    /**
     * @brief Check if a given filename exists in the filesystem.
     * 
     * @param filename 
     * @return true 
     * @return false 
     */
    bool file_exists(char * filename);

    /**
     * @brief Delete a file in the filesystem. If strict is true and file is not present, return false.
     * 
     * @param filename 
     * @param strict 
     * @return true 
     * @return false 
     */
    bool delete_file(char * filename, bool strict=false);

};