/**
 * @file structures.h
 * 
 * @brief Declerations of data structures that can be used throughout this project.
 * @version 0.1
 * @date 2021-06-25
 * 
 * @todo Eventually rewrite the vector implementation while not changing the interface.
 *       This implementation is not ineffient, but could likely be optimized for the
 *       ESP32 microcontroller. 
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef STRUCTURES_H
#define STRUCTURES_H


namespace ledstd{

    /**
     * @brief bad implementation of a vector. Do not really recommend using this unless needed in the code.
     *        This vector will also work as a queue and a stack as it implements
     *        push_front, push_back, pop_front, pop_back. push_back is amortized O(1), whereas push_front
     *        is O(N). This means, use push_back when possible. Furthermore, pop_back is O(1) whereas
     *        pop_front is O(N).  
     * 
     * @tparam T 
     * @tparam Size 
     */
    template<class T, int Size>
    class vector{ 
    
        public:
            vector();
            ~vector(); 

            /**
             * @brief Append an element to the back of the structure. 
             * 
             * @param elt 
             */
            void push_back(T elt); 

            /**
             * @brief Append an element to the front of the structure. 
             * 
             * @param elt 
             */
            void push_front(T elt); 

            /**
             * @brief Pop the back element of the structure.
             * 
             * @bug does not yet account for the case when size = 1 of size = 0
             * 
             * @param elt 
             * @return T 
             */
            T pop_back();

            /**
             * @brief Pop the frontmost element of the vector. 
             * 
             * @bug does not yet account for the case when size = 1 of size = 0
             * 
             * @param elt 
             * @return T 
             */
            T pop_front();

            /**
             * @brief Return the size
             * 
             * @return unsigned int 
             */
            unsigned int size(); 

            T & at(unsigned int index); 

            T & operator[](unsigned int index); 

            T * begin();
            T * end(); 

        private:

            // Grow the vector by 2.
            void grow();

            // internal storage structure.
            T * datum; 

            unsigned int datum_size;
            unsigned int capacity; 

    };


    /**
     * @brief This is a deque implementation.
     * 
     * @note One of the advantages to using a deque compared to the vector (for my implementation)
     *       Is that for small amounts of data, the deque will be more effient. The deque will
     *       have the first container for data statically allocated, and after that will be
     *       dynamically allocated. This means there will be few dynamic writes, and deleting / adding
     *       should happen in a fast manner. 
     * 
     * @note If iteration is needed, then a vector will be better as the deque suffers from poor
     *       spacial locality. If a queue of stack is needed with constant writes and removals, then the
     *       deque is the way to go with O(1) push and pop operations. 
     * 
     * @note The plan is to implement O(1) random deletion in the deque. I am figuring out the best
     *       way to go about implementing this still, so there is currently no form of random deletion. 
     * 
     * @tparam T 
     * @tparam Capacity 
     * @tparam ContainerSize 
     */
    template<class T, unsigned int Capacity=1, unsigned int ContainerSize=5>
    class deque{

        public:

            deque(); 
            ~deque(); 

            void push_back(T datum); 

            void push_front(T datum);

            T pop_back();

            T pop_front(); 

            unsigned int size(); 

            T & operator[](unsigned int index);

            T & at(unsigned int index); 

        private:

            void grow_front(); 

            void grow_back(); 

            T staticArr[ContainerSize]; // the statically allocated base array
            
            T ** containerPointers; // pointer to arr of pointers

    };

    /**
     * @brief This class represents a queue that uses a circular buffer for maintaining the elts. 
     * 
     * @note Do not overfill buffer. If you push more and BufferSize elts into the RingBuffer,
     *       then there will be undfined behavior. 
     * 
     * @tparam T 
     * @tparam BufferSize 
     */
    template<typename T, unsigned int BufferSize>
    class RingBuffer{
        static_assert(BufferSize > 0, "BufferSize must be greater than zero"); // ensure that the buffer even exists. 
        
        public:

            RingBuffer();
            ~RingBuffer(); 

            /**
             * @brief Get the next element in the queue. 
             * 
             * @return T& 
             */
            T & next();

            /**
             * @brief Push an element into the queue. 
             * 
             * @return T& 
             */
            void push(T elt); 

            /**
             * @brief Removes the next element from the queue. 
             * 
             * @return T& 
             */
            void pop(); 

            /**
             * @brief Get a pointer to the internal buffer
             * 
             * @return T* 
             */
            T * data();

            /**
             * @brief Return the number of elements that are in the ringBuffer. 
             * 
             * @return unsigned int 
             */
            unsigned int size(); 

            /**
             * @brief Check if the queue can fit anymore elts. 
             * 
             * @return true 
             * @return false 
             */
            bool queue_full(); 

        private:

            // Ensure that we know if queue is full or empty. 
            bool fullQueue = false; 
            
            // Represents where the start and end of the buffer are. 
            unsigned int head, tail; 

            T queue[BufferSize]; // The internal data buffer. 

            

    };


}; 

#endif
