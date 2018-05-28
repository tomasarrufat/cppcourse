// Name     : FunctionPointers.cpp

#include <iostream>

void testPrint(std::string input)
{
    std::cout << "Hello " << input << std::endl;
}

int main()
{
    testPrint("world");

    void (*function1)(std::string) = testPrint;

    function1("second world");

    void (*function2)(std::string);

    function2 = testPrint;

    (*function2)("third world");

    return 0;
}

