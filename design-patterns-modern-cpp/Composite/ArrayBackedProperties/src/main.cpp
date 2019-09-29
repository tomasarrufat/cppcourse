#include <cstdio>
#include <vector>
#include <array>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <boost/predef/library/c.h>
#include <boost/predef/library/c.h>
#include <boost/predef/library/c.h>
#include <boost/predef/library/c.h>
using namespace std;

class Creature
{
    int strength, agility, intelligence;
    public:

    int get_strength() const{
        return strength;
    }
    int get_agility() const{
        return agility;
    }
    int get_intelligence() const{
        return intelligence;
    }
    void set_strength(int strength)
    {
        Creature::strength=strength;
    }
    void set_agility(int agility)
    {
        Creature::agility=agility;
    }
    void set_intelligence(int intelligence)
    {
        Creature::intelligence=intelligence;
    }

    double sum() const{
        return strength + agility + intelligence;
    }

    double average() const{
        return sum() / 3.0;
    }

    int max() const{
        return ::max(::max(strength, agility), intelligence);
    }
};

class CreatureA
{
    enum Abilities { str, agl, intl, count };
    array<int, count> abilities;

    public:

    int get_strength() const{
        return abilities[str];
    }
    int get_agility() const{
        return abilities[agl];
    }
    int get_intelligence() const{
        return abilities[intl];
    }
    void set_strength(int strength)
    {
        CreatureA::abilities[str]=strength;
    }
    void set_agility(int agility)
    {
        CreatureA::abilities[agl]=agility;
    }
    void set_intelligence(int intelligence)
    {
        CreatureA::abilities[intl]=intelligence;
    }

    int sum() const {
        return accumulate(abilities.begin(), abilities.end(), 0);
    }

    double average() const {
        return sum() / (double) count;
    
    }

    int max() const {
        return *max_element(abilities.begin(), abilities.end());
    }

};


int main(int ac, char* av[])
{
    CreatureA orc;
    orc.set_strength(16);
    orc.set_agility(11);
    orc.set_intelligence(9);

    cout << "The orc has an average stat of "
         << orc.average()
         << " and a maximum stat of "
         << orc.max() << endl;
}
