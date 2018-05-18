// Name     : MultiMap.cpp

#include <iostream>
#include <map>



int main()
{

    std::multimap<int, std::string> lookup;

    lookup.insert(std::pair<int, std::string>(1, "Tomas"));
    lookup.insert(std::pair<int, std::string>(2, "Pepe"));
    lookup.insert(std::pair<int, std::string>(1, "Monica"));
    lookup.insert(std::pair<int, std::string>(3, "Daniela"));

    for( auto it = lookup.begin(); it != lookup.end(); it++ )
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }

    std::cout << "Proviede key to find:" << std::endl;

    int key2Find;
    std::cin >> key2Find;

    auto range = lookup.equal_range(key2Find);

    for( auto it = range.first; it != range.second; it++ )
    {
        std::cout << "Found person: " << it->second << std::endl;
    }

    return 0;
}

