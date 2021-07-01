/**
 * @file ledstd.h
 * 
 * @brief This file contains some standard functions for the led library.
 * @version 0.1
 * @date 2021-06-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

namespace ledstd{

    template<typename T, typename If_Valid>
    struct is_integral{}; 

    template<typename If_Valid>
    struct is_integral<int, If_Valid>{using Type = If_Valid}; 

};