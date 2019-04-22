#pragma once
#include <iostream>
//#include <string>
//#include <vector>
//#include <sstream>
//#include <memory>

class PersonBuilder;

class Person
{
    //address
    std::string street_address, post_code, city;

    //employment
    std::string company, position;
    int annual_income{0};

    Person()
    {
        std::cout << "Person created\n";
    }

  public:
    static PersonBuilder create();

    Person(Person &&other)
        : street_address{move(other.street_address)},
          post_code{move(other.post_code)},
          city{move(other.city)},
          company{move(other.company)},
          position{move(other.position)},
          annual_income{other.annual_income}
    {
    }

    Person &operator=(Person &&other)
    {
        if (this == &other)
            return *this;
        street_address = move(other.street_address);
        post_code = move(other.post_code);
        city = move(other.city);
        company = move(other.company);
        position = move(other.position);
        annual_income = other.annual_income;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Person &obj)
    {
        return os
               << "street_address: " << obj.street_address
               << " post_code: " << obj.post_code
               << " city: " << obj.city
               << " company: " << obj.company
               << " position: " << obj.position
               << " annual_income: " << obj.annual_income;
    }

    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;
};