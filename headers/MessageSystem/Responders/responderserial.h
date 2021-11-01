/**
 * @file responderserial.h
 * 
 * @brief The Serial responder system
 * @version 0.1
 * @date 2021-08-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "responderbase.h"

#ifndef RESPONDERSERIAL_H
#define RESPONDERSERIAL_H

class SerialResponder : public ResponderBase {
public:

SerialResponder();
~SerialResponder();

virtual ResponseError sendDataUntilByte(const char * data, char endByte, int length = -1);

virtual ResponseError sendDataUntilLength(const char * data, unsigned int length);

protected:
virtual ResponseError enable_component();

private:


};

#endif