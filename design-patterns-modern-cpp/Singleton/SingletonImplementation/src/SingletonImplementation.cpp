#include <iostream>
#include <fstream>
#include <memory>
#include <map>
#include <boost/lexical_cast.hpp>

using namespace std;

class SingletonDatabase
{
    SingletonDatabase()
    {
        cout << "Initializing database.\n";
        fstream ifs("countries");

        string s, s2;

        while(getline(ifs, s))
        {
            getline(ifs, s2);
            //cout << s << " " << s2 << endl;
            int population = boost::lexical_cast<int>(s2);
            capitals[s] = population;
        }
    }

    map<string, int> capitals;
    public:
    SingletonDatabase(SingletonDatabase const&) = delete;
    void operator=(SingletonDatabase const&) = delete;

    static SingletonDatabase& get()
    {
        static SingletonDatabase db;
        return db;
    }

    int getPopulation(const string& name)
    {
        return capitals[name];
    }

};

int main()
{
    string country{"Madagascar"};
    cout << country << " has population of: " <<
    SingletonDatabase::get().getPopulation("Madagascar") << "\n";

    return 0;
}