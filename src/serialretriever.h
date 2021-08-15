/**
 * @file serialretriever.h
 *
 * @brief The serial message retriever. This will accept messages over serial.
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "messageretriever.h"

#ifndef SERIALRETRIEVER_H
#define SERIALRETRIEVER_H

/**
 * @brief The class that represents the Serial retriever.
 * 
 * @note Derived from class declared in "messageretriever.h"
 * 
 */
class SerialRetriever : public MessageRetrieverBase {

public:

    SerialRetriever();
    ~SerialRetriever();

    virtual void setupRetriever() override; 
    virtual void updateRetriever() override; 

private:

};

#endif