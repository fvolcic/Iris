/**
 * @file thread.h
 * 
 * @brief This contains the entire threading interface. The threading interface allows the programmer
 *        to create threads, manage current threads, and other such operations.
 * @version 0.1
 * @date 2021-07-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief 
 * 
 */
namespace Thread{

    /**
     * @brief thread_handle is an alias for a thread object that can be manipulated. 
     * 
     */
    using thread_handle = void; 

    /**
     * @brief Config structure for a new thread
     * 
     */
    struct thread_config{}; 

    /**
     * @brief Create a thread object using the given config
     * 
     * @param config 
     * @return thread_handle 
     */
    thread_handle create_thread(thread_config * config); 

};