/**
 * @file enum.h
 * 
 * @brief Provide an interface for enums. 
 * @version 0.1
 * @date 2021-06-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief Creat an enum class with the given name, but automatically supply special
 *        arg to keep track of the enum size.
 * 
 */
#define ENUM(name, ...) enum class name { __VA_ARGS__ , _COUNT_ } 

/**
 * @brief Get the size of an enum defined with the ENUM macro. 
 * 
 */
//#define ENUMSIZE(enum_class) static_cast<unsigned int> (enum_class::_COUNT_)
#define ENUMSIZE(enum_class, valtype) static_cast<valtype> (enum_class::_COUNT_)