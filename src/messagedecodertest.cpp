/**
 * @file messagedecodertest.cpp
 * 
 * @brief File contains an example message decoder.
 * @version 0.1
 * @date 2021-07-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "messagedecodertest.h"
#include "utils.h"
#include "storage.h"

using namespace Utils::LEDSerial; 

const char * ExampleDecoder::get_key() {
    return this->msgKey; 
}

/**
 * @brief Allows the user to inquire about the data currently stored on the spiffs filesystem
 * 
 * @param doc 
 * @return true 
 * @return false 
 */
bool ExampleDecoder::decode(JsonDocument * doc) {
    initializeSerial();
    print("Received New Data\n"); 
    print(doc->data().asString()); 

    Filesystem::launch(); 

    const char * filename = (*doc)["file"];
    
    bool save = (*doc)["save"];

    if(save){
        char * datum = (char *)(const char *)(*doc)["data"];
        Filesystem::store_data(filename, datum); 
        print("Saved new file as: ");
        print_char_until(filename, '\0', 100);
        print("\n"); 
        return true; 
    }

    print_char_until(filename, '\0', 10); 
    print("\n");

    if(!Filesystem::file_exists(filename)){
        print("File does not exist\n");
        return true;
    }

    char * data = Filesystem::get_data(filename); 
    print_char_until(data, '\0', MAX_MESSAGE_LENGTH);

    return true;
}

const char ExampleDecoder::msgKey[] = "example"; 