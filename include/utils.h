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

#include "globals.h"

#ifndef UTILS_PIO_H
#define UTILS_PIO_H

namespace Utils
{

    /**
     * @brief The namespace for all the serial communication that can be used.
     * 
     * @todo Rename finalSerialByte and then find a new location for it. I don't love finalSerialByte
     *       being placed here, but it will work for now.
     * 
     */
    namespace LEDSerial{

        // boolean that tells us if the serial has already been initialized.
        extern bool serialInitialized;// = false; 
        extern char finalSerialByte;// = '\0'; 

        /**
         * @brief Initialize the program serial. 
         * 
         * @note If serial is already initialized, then initialize serial wont do anything. 
         */
        void initializeSerial(unsigned long baudRate = BAUD);

        /**
         * @brief Writes serial data.
         * 
         * @tparam T 
         * @param datum 
         */
        template<typename T>
        void print(T datum);

        /**
         * @brief Return true if there is serial available.
         * 
         * @return true 
         * @return false 
         */
        bool serialAvailable();

        /**
         * @brief Read a serial data stream until a given byte is seen.
         * 
         * @note Forward write iterator is required.
         *       The iterator must support operator++ and write. 
         *       (Since these are the only required operations, a char * will work) 
         * 
         * @note Terminating character is not read into the buffer. 
         * 
         * @param endByte The terminating byte
         * @param buffer The buffer to read into
         * @param length The maximum read length
         * @param timeout The time until the read should fail for taking too long
         * 
         * @return True
         *         False
         *         -> Returns false if the read fails. Returns true otherwise.
         */

        bool readSerialUntil(char endByte, char *  buffer, unsigned int length = MAX_MESSAGE_LENGTH, unsigned long timeout = 1000);
    };

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
        template <bool PASS_VAL, bool STRICT = false>
        bool runtime_assert(bool val);

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
        extern void (*RESET)(void);

    };


    /**
     * @brief Check if a value is a nullptr.
     * 
     * @tparam T 
     * @param val 
     * @return true 
     * @return false 
     */
    template<typename T>
    bool is_nullptr(T val);
};

#endif