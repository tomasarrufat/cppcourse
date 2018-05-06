#include <iostream>

void print()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto x : v)
        std::cout << x << '\n';
    // for each x in v
    for (auto x : {10, 21, 32, 43, 54, 65})
        std::cout << x << '\n';
    // ...
}

void increment()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto& x : v)
        x++;

    for (auto x : v)
        std::cout << x << '\n';
}

//void print(int a)
//{
//    std::cout << "In array there is:" << '\n';
//    for (auto elem : a)
//        std::cout << elem << '\n';
//}

int main()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //print();
    increment();
}