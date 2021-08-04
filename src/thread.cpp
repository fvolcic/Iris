/**
 * @file thread.cpp
 * 
 * @brief This defines all functionality declared in thread.h
 * @version 0.1
 * @date 2021-07-28
 * 
 * @copyright Copyright (c) 2021
 *
 * 
 * @note espressif freeRTOS: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/freertos.html 
 */

#include "thread.h"
#include "SYSTEM_CONFIG.h"

Thread::thread_handle Thread::create_thread(Thread::thread_config * config){
#ifdef USING_FREE_RTOS
    if(config->pinToCore){
        xTaskCreatePinnedToCore(config->task, nullptr, config->stackDepth, nullptr, config->taskPriority, config->handle, config->coreId); 
    }
    else if(!config->pinToCore){
        xTaskCreate(config->task, nullptr, config->stackDepth, nullptr, config->taskPriority, config->handle); 
    }
    return config->handle; 
#endif
}

void Thread::delete_task(thread_handle * handle){
    #ifdef USING_FREE_RTOS
        vTaskDelete(handle); 
    #endif
}