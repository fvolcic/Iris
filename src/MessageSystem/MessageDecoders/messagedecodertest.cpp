/**
 * @file messagedecodertest.cpp
 * 
 * @brief File contains an example message decoder. Essentially, this outlines what a new
 *        decoder will have to look like. This implements the necessary overrides 
 *        for a full implementation. ExampleDecoder allows access to the internal
 *        file system from a message, and then prints the result to serial.      
 *  
 * @version 0.1
 * @date 2021-07-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "MessageSystem/MessageDecoders/messagedecodertest.h"
#include "MessageSystem/messagesystem.h"
#include "System/storage.h"
#include "Utils/utils.h"
#include "MessageSystem/Responders/respondersystem.h"

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
    // print( doc );
    print(doc->data().asString().c_str()); 
    print("HERE!"); 

    Filesystem::launch(); 

    const char * filename = (*doc)["file"];
    
    bool save = (*doc)["save"];
    bool format = (*doc)["format"]; 
    bool deletefile = (*doc)["delete"];
    bool help = (*doc)["help"];
    bool encrypt = (*doc)["encrypt"];
    bool decrypt = (*doc)["decrypt"]; 
    bool kill = (*doc)["kill"];
    bool enable = (*doc)["enable"];
    bool disable = (*doc)["disable"];
    bool sayhi = (*doc)["hello"];

    if(enable){
        Respond::enableAllResponders();
        return true;
    }
    if(disable){
        Respond::disableAllResponders();
        return true; 
    }
    if(sayhi){
        Respond::sendDataUntilByte("The Responder says hello!", '\0');
        return true;
    }
    if(kill){
        print("Killing message system\n");
        MessageSystem::killMessageSystem();
        print("Killed\n"); // Not sure if we will reach this line or not
        return true;
    }

    if(help){
        print("Welcome to the example decoder.\n");
        print("To delete, set the \"delete\" flag\n");
        print("To save, set the \"save\" flag\n");
        print("To format, set the \"format\" flag\n");
        return true;
    }
    if(save){
        char * datum = (char *)(const char *)(*doc)["data"];
        Filesystem::store_data(filename, datum); 
        print("Saved new file as: ");
        print_char_until(filename, '\0', 100);
        print("\n"); 
        return true; 
    }
    if(format){
        print("Formatting filesystem...\n");
        Filesystem::format_filesystem();
        print("Finished Formatting\n");
        return true;
    }
    if(deletefile){
        Filesystem::delete_file(filename);
        print("Finished deleting ");
        print_char_until(filename, '\0', 100);
        print("\n");
        return true;
    }
    if(encrypt){
        print("Saving encrypted data...\n");
        char * datum = (char *)(const char *)(*doc)["data"];
        Filesystem::store_encrypted_block(filename, datum, nullptr);
        print("Finished encrypted data save\n");
        return true;
    }

    print_char_until(filename, '\0', 10); 
    print("\n");

    if(!Filesystem::file_exists(filename)){
        print("File does not exist\n");
        return true;
    }/**
 * @brief 
 * 
 * @param filename 
 * @param datum 
 * @param key 
 * @return true 
 * @return false 
 */

    if(decrypt){
        char * data = Filesystem::get_encrypted_block(filename, nullptr);
        print_char_until(data, '\0', MAX_MESSAGE_LENGTH);
        delete[] data; 
    }

    char * data = Filesystem::get_data(filename); 
    print_char_until(data, '\0', MAX_MESSAGE_LENGTH);

    delete[] data; 

    return true;
}

const char ExampleDecoder::msgKey[] = "example"; 
