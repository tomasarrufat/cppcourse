#pragma once

#include "PersonBuilder.h"
#include <string>

class PersonJobBuilder : public PersonBuilderBase
{
    typedef PersonJobBuilder Self;

  public:
    explicit PersonJobBuilder(Person &person) : PersonBuilderBase(person){};

    Self &at(std::string company)
    {
        person.company = company;
        return *this;
    }

    Self &as(std::string position)
    {
        person.position = position;
        return *this;
    }

    Self &earns(int salary)
    {
        person.annual_income = salary;
        return *this;
    }
};