

struct test{

    int testme(){
        return 5; 
    }

};

struct b{

    test * arr[1] = { new test() }; 

};

#include "iostream"

int main(){
    b a = b();

    std::cout << a.arr[0]->testme() << std::endl;
}