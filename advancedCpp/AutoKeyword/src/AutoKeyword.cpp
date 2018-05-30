// Name     : AutoKeyword.cpp

#include <iostream>

template<class T, class K>   
auto test(T input1, K input2 ) -> decltype(input1 + input2)
{
    return input1 + input2;
}

int main()
{
    //std::cout << test("Hello ", "world!") << std::endl;

    auto text = "Hello world";

    std::cout << test( text, 7 ) << std::endl;

    std::cout << test(10, 23) << std::endl;

    return 0;
}

