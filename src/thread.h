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

#include <Arduino.h>

/**
 * @brief 
 * 
 */
namespace Thread{

    /**
     * @brief thread_handle is an alias for a thread object that can be manipulated. 
     * 
     */
    using thread_handle = TaskHandle_t; 

    /**
     * @brief Config structure for a new thread
     * 
     */
    struct thread_config{
        bool pinToCore = false;
        unsigned int core = 0;
        unsigned int stackDepth;
        unsigned int taskPriority = 0; 
        unsigned int coreId = tskNO_AFFINITY; // INT_MAX
    }; 

    /**
     * @brief Create a thread object using the given config
     * 
     * @param config 
     * @return thread_handle 
     */
    thread_handle create_thread(thread_config * config); 

    /**
     * @brief Macro is used to delay a given task for a given number of ticks.
     * 
     */
    #define delayTask(ticks) vTaskDelay( (ticks) ); 

    /**
     * @brief Will delete a task and remove from the thread pool
     * 
     * @param task 
     */
    void delete_task(thread_handle task); 

};