#include "structures.h"
#include "unit_test_framework.h"

#include <iostream>

TEST(TestRingBufferPushPop){

    ledstd::RingBuffer<int, 10> queue; 
    for(int i = 0; i < 10; ++i)
        queue.push(i); 
    
    for(int i = 0; i < 5; ++i){
        ASSERT_EQUAL(queue.next(), i);
        queue.pop();  
    }

    queue.push(3); 
    
    ASSERT_EQUAL(queue.next(), 5); 
}

TEST(testRingBufferSize){
    ledstd::RingBuffer<int, 10> queue; 
    
    ASSERT_FALSE(queue.queue_full()); 

    for(unsigned int i = 0; i < 10; ++i){
        queue.push(i); 
        ASSERT_EQUAL(queue.size(), i+1); 
    }

    ASSERT_TRUE(queue.queue_full()); 

    for(unsigned int i = 0; i < 4; ++i){ 
        queue.pop();
        ASSERT_FALSE(queue.queue_full()); 
        ASSERT_EQUAL(queue.size(), 9 - i);
    }

    queue.push(1); 
    queue.push(2); 
    queue.push(3); 

    ASSERT_EQUAL(queue.size(), 9); 

}


TEST_MAIN()