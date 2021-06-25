/**
 * @file structures.h
 * 
 * @brief A simple queue implementation for use in this project.
 * @version 0.1
 * @date 2021-06-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

namespace ledstd{

    template<class T, int Size=1>
    class vector{ 
        static_assert(Size>0); 

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

            T at(unsigned int index); 

            T operator[](unsigned int index); 

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

}; 