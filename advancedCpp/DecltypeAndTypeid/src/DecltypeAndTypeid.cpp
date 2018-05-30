// Name     : DecltypeAndTypeid.cpp

#include <iostream>
#include <typeinfo>

int main()
{
    double valueDouble;
    int valueInt;
    char valueChar;
    std::string valueString;

    decltype(valueDouble) typeCopy;

    std::cout << "Double value has typeid.name: " << typeid(valueDouble).name() << std::endl;
    std::cout << "Int value has typeid.name: " << typeid(valueInt).name() << std::endl;
    std::cout << "Char value has typeid.name: " << typeid(valueChar).name() << std::endl;
    std::cout << "String value has typeid.name: " << typeid(valueString).name() << std::endl;
    std::cout << "Copy value has typeid.name: " << typeid(typeCopy).name() << std::endl;

    return 0;
}

