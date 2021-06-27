#include "structures.h"
#include "unit_test_framework.h"

//

TEST(TestRingBuffer){

    ledstd::RingBuffer<int, 10> queue; 
    for(int i = 0; i < 10; ++i)
        queue.push(i); 
    
    ASSERT_EQUAL(queue.next(), 0); 

}


TEST_MAIN()