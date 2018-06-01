// Name     : C++Initialization.cpp

#include <iostream>

class A{
    public: 
        int age;
        std::string name;
};

class B{
    private:
        int age = 10;
        std::string name = "Default";

    public:
        int getAge(){ return age;};
        std::string getName(){ return name;};
};

struct C{
    int age;
    std::string name;
};

struct E{
        int age = 27;
        std::string name = "Tomas";
};

int main()
{
    A a1 = {27, "Pedro"};
    B b1 = {};
    C c1 = {30, "Anna"};
    E e1 = {};

    struct{
        int age;
        std::string name;
    } d1 = {21, "Sonia"}, d2 = {33, "Natasha"};

    std::cout << a1.name << " : " << a1.age << std::endl;
    std::cout << b1.getName() << " : " << b1.getAge() << std::endl;
    std::cout << c1.name << " : " << c1.age << std::endl;
    std::cout << d1.name << " : " << d1.age << std::endl;
    std::cout << d2.name << " : " << d2.age << std::endl;
    std::cout << e1.name << " : " << e1.age << std::endl;

    return 0;
}

