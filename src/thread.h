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
#include "SYSTEM_CONFIG.h"

/**
 * @brief Threading interface for freeRTOS
 * 
 */
#ifdef USING_FREE_RTOS
namespace Thread{

    // Different alias' for modularizing the code
    using thread_handle = TaskHandle_t; 
    using TaskFunction = TaskFunction_t; 


    /**
     * @brief Config structure for a new thread
     * 
     */
    struct thread_config{
        bool pinToCore = false;
        unsigned int core = 0;
        unsigned int stackDepth = 1000;
        unsigned int taskPriority = 0; 
        unsigned int coreId = tskNO_AFFINITY; 
        TaskFunction task; 
        thread_handle * handle;
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
     * @brief Requirements for what should be placed in the a task function
     * 
     */
    #define task_param_requirements void *

    /**
     * @brief Get the handle of a function for a thread
     * 
     * @param task function name to get task handle from
     */
    #define getTaskEntry(task) & (task) 

    /**
     * @brief End current task. Must be called inside a
     *        running task. "This" is self referential
     * 
     */
    #define endThisTask() (vTaskDelete(NULL))

    /**
     * @brief Will delete a task and remove from the thread pool
     * 
     * @param task 
     */
    void delete_task(thread_handle * handle); 

};
#endif