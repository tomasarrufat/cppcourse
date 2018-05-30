// Name     : RangeBasedForLoop.cpp

#include <iostream>
#include <vector>

template<class T>
void printIterable(T inputs)
{
    std::cout << "Printing stuff:" << std::endl;

    for(auto input : inputs)
    {
        std::cout << input << std::endl;
    }
}

int main()
{
    auto texts = {"one", "two", "three", "four", "five", "six", "seven"};
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::string hello = "Hello world!";

    printIterable<decltype(texts)>(texts);
    printIterable<decltype(numbers)>(numbers);
    printIterable<decltype(hello)>(hello);

    return 0;
}

