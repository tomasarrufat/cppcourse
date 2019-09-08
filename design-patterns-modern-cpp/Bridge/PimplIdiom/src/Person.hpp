#pragma once
#include <string>
#include <iostream>

class Person {
public:
    std::string name;

    class PersonImpl;
    PersonImpl* impl;

    Person();
    ~Person();

    void greet();
    
};