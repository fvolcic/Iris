/**
 * @file structures.cpp
 * 
 * @brief Defintions for structures.h
 * @version 0.1
 * @date 2021-06-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "structures.h"


//*****************************************************************
//*                           Vector                              *
//*****************************************************************

template<class T, int Size>
ledstd::vector<T, Size>::vector() : datum_size(0), capacity(Size)
{
    datum = new T[Size]; 
}

template<class T, int Size>
ledstd::vector<T, Size>::~vector()
{
    delete[] datum; 
}

template<class T, int Size>
T ledstd::vector<T, Size>::pop_back()
{
    this->datum_size -= 1; 
    return this->datum[datum_size]; 
}


template<class T, int Size>
T ledstd::vector<T, Size>::pop_front()
{
    T tmp = datum[0]; 
    for(int i = 0; i < datum_size; ++i)
        datum[i] = datum[i + 1]; 
        datum_size-=1;
    return tmp; 
}


template<class T, int Size>
void ledstd::vector<T, Size>::push_front(T datum)
{
    if(this->datum_size == this->capacity)
        grow(); 
    for(unsigned int i = datum_size - 1; i >= 0; --i)
        this->datum[i + 1] = this->datum[i]; 
    this->datum[0] = datum; 
    
}

template<class T, int Size>
void ledstd::vector<T, Size>::push_back(T datum)
{
    if(this->datum_size == this->capacity)
        grow(); 
    this->datum[datum_size++] = datum; 
}

template<class T, int Size>
unsigned int ledstd::vector<T, Size>::size()
{
    return datum_size; 
}

template<class T, int Size>
void ledstd::vector<T, Size>::grow()
{
    T * tmp = new T[datum_size * 2]; 
    for(int i = 0; i < datum_size; ++i)
        tmp[i] = datum[i];
    delete[] datum; 
    datum = tmp; 
    capacity *= 2; 
}

template<class T, int Size>
T * ledstd::vector<T, Size>::begin(){
    return datum; 
}

template<class T, int Size>
T * ledstd::vector<T, Size>::end(){
    return datum + datum_size; 
}

template<class T, int Size>
T & ledstd::vector<T, Size>::at(unsigned int index){
    return datum[index]; 
}

template<class T, int Size>
T & ledstd::vector<T, Size>::operator[](unsigned int index){
    return datum[index];
}


//*****************************************************************
//*                       RingBuffer                              *
//*****************************************************************

template<class T, unsigned int BufferSize>
ledstd::RingBuffer<T, BufferSize>::RingBuffer() : head(0), tail(0){}

template<class T, unsigned int BufferSize>
ledstd::RingBuffer<T, BufferSize>::~RingBuffer(){}

template<class T, unsigned int BufferSize>
void ledstd::RingBuffer<T, BufferSize>::push(T elt){
    queue[tail] = elt; 
    tail = (++tail) % BufferSize;  

    if(tail == head)
        fullQueue = true;
}

template<class T, unsigned int BufferSize>
void ledstd::RingBuffer<T, BufferSize>::pop(){
    head = (++head) % BufferSize; 

    if(fullQueue)
        fullQueue = false; 
}

template<class T, unsigned int BufferSize>
T & ledstd::RingBuffer<T, BufferSize>::next(){
    return queue[head]; 
}

template<class T, unsigned int BufferSize>
T * ledstd::RingBuffer<T, BufferSize>::data(){
    return queue; 
}

template<class T, unsigned int BufferSize>
unsigned int ledstd::RingBuffer<T, BufferSize>::size(){
    if(fullQueue && head==tail)
        return BufferSize;

    if(tail >= head)
        return tail - head; 
    
    return tail + BufferSize - head; 
}
template<class T, unsigned int BufferSize>
bool ledstd::RingBuffer<T, BufferSize>::queue_full(){
    return fullQueue; 
}

// RingBuffer template instantiations below. Needed for the linking stage of compilation.

template class ledstd::RingBuffer<int, 5u>; 