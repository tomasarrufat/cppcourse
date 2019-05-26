#include <iostream>
#include <fstream>
#include <memory>
#include <map>
#include <boost/lexical_cast.hpp>
#include "TestabilityIssues.hpp"

using namespace std;


int main()
{
    string country{"Madagascar"};
    cout << country << " has population of: " << SingletonDatabase::get().getPopulation("Madagascar") << "\n";

    return 0;
}