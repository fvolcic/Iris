

template<typename T, typename If_Valid>
    struct is_integral{}; 

template<typename If_Valid>
struct is_integral<int, If_Valid>{using Type = If_Valid;}; 

int main(){ 

    typename is_integral<int, double>::Type test = 3; 

    return test; 
}