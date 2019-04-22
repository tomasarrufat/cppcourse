#pragma once
#include <iostream>
//#include <string>
//#include <vector>
//#include <sstream>
//#include <memory>
#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase
{
  protected:
    Person &person;

    explicit PersonBuilderBase(Person &person)
        : person{person} {};

  public:
    operator Person() const
    {
        return std::move(person);
    };

    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase
{
    Person p;

  public:
    PersonBuilder() : PersonBuilderBase(p){};
};
