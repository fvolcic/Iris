/**
 * @file utils.h
 * 
 * @brief Provide some miscellaneous tools for use throughout the code.
 * 
 * @version 0.1
 * @date 2021-06-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef UTILS_PIO_H
#define UTILS_PIO_H

namespace Utils
{

    /**
     * @brief Retrieve a random number.
     * 
     * @note This function gaurentees a cryptographically secure random number.
     * 
     * @return unsigned int 
     */
    unsigned int random();

    /**
     * @brief Namespace housing the comparison tools.
     * 
     */
    namespace Compare
    {
        /**
         * @brief Compare '\0' terminated c-strings. 
         * 
         * @note do not use this function if cryptography is important (ex. password comparison)
         * 
         * @param c_str1 
         * @param c_str2 
         * @return true 
         * @return false 
         */
        bool cstrcmp(const char *c_str1, const char *c_str2);

        /**
         * @brief Compare two char arrays
         * 
         * @note Do not need to be '\0' terminated, but their length must be known prior to
         *       using this function.
         * 
         * @note do not use this function if cryptography is important (ex. password comparison)
         * 
         * @param c_str1 
         * @param c_str1_len 
         * @param c_str2 
         * @param c_str2_len 
         * @return true 
         * @return false 
         */
        bool cstrcmp(const char *c_str1, unsigned int c_str1_len, const char *c_str2, unsigned int c_str2_len);
    };

    /**
     * @brief Functionality regaurding asserts which can be used in the program. 
     * 
     */
    namespace Asserts
    {
        /**
         * @brief Create a dynamic assertion that will only pass if val == PASS. 
         * 
         * @tparam PASS - required value needed for the assert to pass
         * @tparam STRICT - If true, the program will reset on a failure. 
         * @param val 
         */
        template <bool PASS, bool STRICT = false>
        bool assert(bool val);

    };

    /**
     * @brief Provide interface for different tools that can be used to interface with the program.
     * 
     */
    namespace Program
    {
        /**
     * @brief This allows the program to be completely reset in software. 
     * 
     * @note This works by creating an invalid call, causing freeRTOS to stop the program and reboot.
     *       Use this carefully. 
     * 
     */
        void (*RESET)(void) = 0;

    };
};

#endif