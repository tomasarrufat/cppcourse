// Name     : Bind.cpp

#include <iostream>
#include <functional> // std::bind()

int add(int a, int b, int c){
    std::cout << a << " + " << b << " + " << c << " = " << std::flush;
    return a + b + c;
};

int fun(int a, std::function<int(int)> sum)
{
    return sum(a);
};

class Test{
    int number = 10;

    public:
        Test(int pNumber): number(pNumber){};
        int add(int a, int b, int c){
            std::cout << a << " + " << b << " + " << c << " + " << number << " = " << std::flush;
        return a + b + c + number;
    };
};

int main()
{
    
    std::cout << add(1, 4, 5) << std::endl;

    auto addition = std::bind(add, std::placeholders::_1, 2, 3);

    std::cout << addition(20) << std::endl;

    auto addForFun = std::bind(add, std::placeholders::_1, std::placeholders::_1, std::placeholders::_1);

    std::cout <<  fun(5, addForFun) << std::endl;

    Test ten{25};

    auto addForFunTest = std::bind(&Test::add, ten, std::placeholders::_1, std::placeholders::_1, std::placeholders::_1);

    std::cout <<  fun(5, addForFunTest) << std::endl;

    return 0;
}

