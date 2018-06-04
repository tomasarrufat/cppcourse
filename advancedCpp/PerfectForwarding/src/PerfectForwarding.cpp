// Name     : PerfectForwarding.cpp

#include <iostream>

class Test{

};

template<typename T>
void call(T &&arg){
    check(std::forward<T>(arg));
};

void check(Test &test){
    std::cout << "This is an lvalue reference." << std::endl;
};
void check(Test &&test){
    std::cout << "This is an rvalue reference." << std::endl;
};

int main()
{
    Test test;

    //When C++ inferes some types sometimes doesn't get right the lvalue or rvalue.

    call(test);
    call(Test());
    
    return 0;
}

