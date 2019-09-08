#include "Person.hpp"

class Person::PersonImpl
{
public:
    void greet(Person* p);
};

void Person::PersonImpl::greet(Person *p) {
    std::cout << "hello my name is "
            << p->name << std::endl;
}

Person::Person()
: name("jacov"), impl(new PersonImpl){

}

Person::~Person() {
    delete impl;
}

void Person::greet() {
    impl->greet(this);
}