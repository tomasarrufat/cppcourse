// Name     : Functors.cpp

#include <iostream>

struct Test
{
    virtual bool operator()(std::string input) = 0;

    ~Test(){};
};

struct LionTest: public Test
{
    bool operator()(std::string input)
    {
        return input == "Lion" || input == "lion";
    }
};

struct CatTest: public Test
{
    bool operator()(std::string input)
    {
        return input == "Cat" || input == "cat";
    }
};

void checkText( std::string text, Test &test )
{
    if(test(text))
    {
        std::cout << "Text matches!" << std::endl;
    }
    else
    {
        std::cout << "No match." << std::endl;
    }
};

int main()
{
    LionTest matchLion;
    CatTest matchCat;

    std::string animal = "Lion";

    checkText( animal, matchLion );
    checkText( animal, matchCat );

    return 0;
}

