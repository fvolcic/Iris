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
T ledstd::vector<T, Size>::at(unsigned int index){
    return datum[index]; 
}

template<class T, int Size>
T ledstd::vector<T, Size>::operator[](unsigned int index){
    return datum[index];
}


#include <iostream> 
int main(){
    ledstd::vector<int, 1> v; 
    for(int i = 0; i < 1000; ++i){
        v.push_back(i); 
    }
    std::cout << v.size() << std::endl; 

    for(auto i = v.begin(); i != v.end(); ++i){
        std::cout << *i << std::endl; 
    }

    for(int i = 0; i < 100; ++i){
        std::cout << v.pop_back() << std::endl; 
        std::cout << v.pop_front() << std::endl; 
    }

    for(int i = 0; i < 800; ++i){
        std::cout << v[i] << std::endl; 
    }
}