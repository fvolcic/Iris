/**
 * @file thread.cpp
 * 
 * @brief This defines all functionality declared in thread.h
 * @version 0.1
 * @date 2021-07-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "thread.h"
#include "SYSTEM_CONFIG.h"

Thread::thread_handle Thread::create_thread(Thread::thread_config * config){
    Thread::thread_handle handle; 
    
#ifdef USING_FREE_RTOS
    if(config->pinToCore){
        xTaskCreatePinnedToCore(config->task, nullptr, config->stackDepth, nullptr, config->taskPriority, &handle, config->coreId); 
    }
    if(!config->pinToCore){
        
    }
#endif

}