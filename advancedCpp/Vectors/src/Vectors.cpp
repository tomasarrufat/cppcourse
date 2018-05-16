// Name     : Vectors.cpp

#include <iostream>
#include <vector>
#include <exception>


int main()
{
    std::vector<std::string> strings(2);

    strings[0] = "one";
    strings[1] = "two";
    strings.push_back("three");
    strings.push_back("four");
    strings.push_back("five");

    std::cout << strings[0] << std::endl;
    std::cout << strings[1] << std::endl;
    std::cout << strings[2] << std::endl;
    std::cout << strings[3] << std::endl;
    
    try
    {
        //std::cout << strings[4] << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout<< "Gought exception probably out of bounds: " << e.what() << std::endl;
    }
    
    try
    {
        std::cout << strings.at(4) << std::endl;
    }
    catch(std::out_of_range &e)
    {
        std::cout<< "Cought exception out of range: " << e.what() << std::endl;
    }

    std::cout << "Size of strings: " << strings.size() << std::endl;

    std::cout << "Iterate through the vector string with a normal for loop: " << std::endl;

    for( int i = 0; i < strings.size(); i++ )
    {
        std::cout << strings.at(i) << std::endl;
    }

    std::cout << "Iterate through the vector string with c++ 11 for loop: " << std::endl;

    for( std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++ )
    {
        std::cout << *it << std::endl;
    }

    std::cout << "Iterate through the vector string with c++ 14 for loop: " << std::endl;

    for( auto string : strings )
    {
        std::cout << string << std::endl;
    }

    std::cout << "Size of vector: " << strings.size() << std::endl;

    std::cout << "Capacity of vector: " << strings.capacity() << std::endl;

    strings.reserve(10);

    std::cout << "Size of vector: " << strings.size() << std::endl;

    std::cout << "Capacity of vector: " << strings.capacity() << std::endl;

    //Creating a grid of ints with 3 rows and 4 columns.
    const int rows = 3;
    const int columns = 7;

    std::vector<std::vector<int>> grid(rows, std::vector<int>(columns, 1));

    std::cout << "Printing grid: " << std::endl;

    for( auto row : grid )
    {
        for( auto column : row )
        {
            std::cout << column << std::flush;
        }

        std::cout << std::endl;
    }
    

    return 0;
}

