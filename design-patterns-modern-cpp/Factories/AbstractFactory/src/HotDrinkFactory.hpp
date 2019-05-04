#pragma once
#include <iostream>
using namespace std;

#include "HotDring.hpp"

struct HotDrinkFactory // Abstract Factoy
{
    virtual unique_ptr<HotDrink> make() const = 0;
};

struct TeaFactory : HotDrinkFactoy
{
    unique_ptr<HotDrink> make() const override
    {
        return make_unique<Tea>();
    }
};

struct CoffeeFactory : HotDrinkFactoy
{
    unique_ptr<HotDrink> make() const override
    {
        return make_unique<Coffee>();
    }
};  