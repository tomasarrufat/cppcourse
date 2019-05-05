#define _USE_MATH_DEFINES
#include <string>
#include <memory>
#include <iostream>
#include <cmath>
#include <utility>
using namespace std;

#include "HotDrinkFactory.hpp"
#include "DrinkFactory.hpp"

unique_ptr<HotDrink> make_drink(string type)
{
     unique_ptr<HotDrink> drink;

};

int main()
{
    DrinkWithVolumeFactory df;
    auto c = df.make_drink("coffee");
    return 0;
}