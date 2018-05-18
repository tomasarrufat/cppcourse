// Name     : Maps.cpp

#include <iostream>
#include <map>  


int main()
{

    std::map<std::string, int> ages;

    ages["Sergi"] = 56;
    ages["Cecilia"] = 60;
    ages["Pepe"] = 90;
    ages["Helena"] = 88;
    ages["Oriol"] = 19;

    ages.insert(std::pair<std::string, int>("Tomas", 27));

    std::cout << "Introduce name to be searched: ";

    std::string person;

    std::cin >> person;

    if(ages.find(person) != ages.end())
    {
        std::cout << person << " is " << ages[person] << " years old." << std::endl;
    }
    else
    {
        std::cout << "Person not found in database." << std::endl;
    }

    for( auto it = ages.begin(); it != ages.end(); it++ )
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }

    for( auto it = ages.begin(); it != ages.end(); it++ )
    {
        std::pair<std::string, int> age = *it;
        std::cout << age.first << " : " << age.second << std::endl;
    }

    

    return 0;
}

