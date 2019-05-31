#include <iostream>
#include <fstream>
#include <memory>
#include <map>
#include <boost/lexical_cast.hpp>

using namespace std;

class Database
{
public:
    virtual int getPopulation(const string &name) = 0;
};

class SingletonDatabase
{
    SingletonDatabase()
    {
        //cout << "Initializing database.\n";
        fstream ifs("countries");

        string s, s2;

        while (getline(ifs, s))
        {
            getline(ifs, s2);
            //cout << s << " " << s2 << endl;
            int population = boost::lexical_cast<int>(s2);
            countries[s] = population;
        }
    }

    map<string, int> countries;

public:
    SingletonDatabase(SingletonDatabase const &) = delete;
    void operator=(SingletonDatabase const &) = delete;

    static SingletonDatabase &get()
    {
        static SingletonDatabase db;
        return db;
    }

    int getPopulation(const string &name)
    {
        return countries[name];
    }
};

class DummyDatabase : public Database
{
    map<string, int> countries;

public:
    DummyDatabase()
    {
        countries["alpha"] = 1;
        countries["beta"] = 2;
        countries["gamma"] = 3;
    }

    int getPopulation(const string &name) override
    {
        return countries[name];
    }
};

struct SingletonRecordFinder
{
    int totalPopulation(vector<string> names)
    {
        int result{0};
        for (auto &name : names)
            result += SingletonDatabase::get().getPopulation(name);
        return result;
    }
};

struct ConfigurableRecordFinder
{
    Database& db;

    ConfigurableRecordFinder(Database &db) : db(db) {}

    int totalPopulation(vector<string> names)
    {
        int result{0};
        for (auto &name : names)
            result += db.getPopulation(name);
        return result;
    }
};
