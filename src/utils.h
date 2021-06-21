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

namespace Utils{

    /**
     * @brief Functionality regaurding asserts which can be used in the program. 
     * 
     */
    namespace Asserts{
        /**
         * @brief Create a dynamic assertion that will only pass if val == PASS. 
         * 
         * @tparam PASS 
         * @param val 
         */
        template<bool PASS>
        void assert(bool val);  

    }; 

    /**
     * @brief Provide interface for different tools that can be used to interface with the program.
     * 
     */
    namespace Program{
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