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
#include "utils.h"
#include "SYSTEM_CONFIG.h"

#include "printer.h"

Thread::thread_handle Thread::create_thread(Thread::thread_config * config){
#ifdef USING_FREE_RTOS
    if(config->pinToCore){
        PRINT("PINNING THREAD TO CORE");
        xTaskCreatePinnedToCore(config->task, NULL, config->stackDepth, NULL, config->taskPriority, config->handle, config->coreId); 
    }
    else if(!config->pinToCore){
        PRINT("CREATED UNPINNED THREAD\n");
        char name[] = "randomTaskName";
        name[0] = (char) Utils::random();
        xTaskCreate(config->task, name, config->stackDepth, NULL, config->taskPriority, config->handle); 
    }
    PRINT("THREAD CREATED\n");
    return config->handle; 
#endif
}

void Thread::delete_task(thread_handle * handle){
    #ifdef USING_FREE_RTOS
        vTaskDelete(handle); 
    #endif
}