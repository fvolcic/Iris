/**
 * @file interface.h
 *
 * @brief This file represents a different interface options and their settings (BLE, WIFI, Serial).
 * @version 0.1
 * @date 2021-06-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

namespace Interface{

enum class Interfaces { WIFI, MQTT, BT, SERIAL }; 

template<int lower, int upper, int val, typename rtype>
struct ibounded{ 
    static_assert(lower < val); 
    static_assert(upper > val); 
    using TYPE = rtype; 
};

char filename[3 + sizeof(Interface::Interfaces)] = {'I', 'F'}; 

template<int filenum_t, int pos> inline auto _init_filename() -> typename ibounded<0, 9, filenum_t, void>::TYPE {
    Interface::filename[pos] = static_cast<char>(filenum_t) % 10;  
}; 

template<int filenum_t, int pos> inline auto _init_filename() -> typename ibounded<10, 99, filenum_t, void>::TYPE {
    Interface::filename[pos] = static_cast<char>(filenum_t); 
    _init_filename<filenum_t / 10, pos + 1>(); 
};

template<Interface::Interfaces I> 
void _init_filename() {
    _init_filename<static_cast<int>(I), 2>(); 
}; 

template<Interface::Interfaces I> bool enabled(){
    Interface::filename[0] = 'I'; 
    Interface::filename[1] = 'F';  
    _init_filename<I>(); 
    return true; 
}


};


#include <iostream>

using namespace std; 

int main(){

Interface::enabled<Interface::Interfaces::SERIAL>(); 

cout << Interface::filename << endl; 

}; 