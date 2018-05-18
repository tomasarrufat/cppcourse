// Name     : CustomObjectsAsMapsKeys.cpp

#include <iostream>
#include <map>

class Person{

    private:
        std::string name;
        int age;

    public:

        Person(): name("deault"), age(0) {
            std::cout << "Default Person Constructor running." << std::endl;
        };

        Person(const Person & other): name(other.name), age(other.age) {
            std::cout << "Person Copy Constructor running." << std::endl;
        };

        Person( std::string p_name, int p_age): name(p_name), age(p_age) {
            std::cout << "Standard Person Constructor running." << std::endl;
        };
        //First const because we want this method not to modify the RHS
        //Second const because we want this method not to modify the LHS
        bool operator<( const Person &other) const {
            if( age == other.age)
            {
                return name < other.name;
            }
            else
            {
                return age < other.age;
            }
        }

        bool operator>( const Person &other) const { 
            if( age == other.age)
            {
                return name > other.name;
            }
            else
            {
                return age > other.age;
            }
        }

        void print() const //The key of a map needs to be constant
        {
            std::cout << "Person name: " << name << " and age " << age << std::flush;
        }   
};

int main()
{

    std::map<Person, int> people;

    people.insert(std::pair<Person, int>(Person("Tomas", 27),1));

    people[Person("Oriol", 19)] = 2;
    people[Person("Josep", 60)] = 3;
    people[Person("Merce", 50)] = 4;
    people[Person("Pedro", 19)] = 5;

    std::cout << "Printing content of map:" << std::endl;

    for( auto it = people.begin(); it != people.end(); it++ )
    {
        std::cout << it->second << " " << std::flush;
        it->first.print();
        std::cout << std::endl;
    }

    return 0;
}