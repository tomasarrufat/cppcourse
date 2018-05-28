// Name     : TemplateFunctions.cpp

#include <iostream>

void print(const int first, const int second)
{
    std::cout << "Pure version " << first << " : " << second << std::endl;
}

template<class T, class K>
void print(const T first, const K second)
{
    std::cout << "Template version " << first << " : " << second << std::endl;
}




int main()
{
    print("Hello", "world!");

    print<>("I am", 25);

    print(15, "place");

    print<>(1,2);

    return 0;
}

