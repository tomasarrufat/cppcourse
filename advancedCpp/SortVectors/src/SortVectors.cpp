// Name     : SortVectors.cpp

#include <iostream>
#include <vector>
#include <algorithm> // std::sort

class Person
{
    private:
        std::string name;
        std::string email;
        int age;
    public:
    // Methods
        Person( const Person & other ): name(other.name), email(other.email), age(other.age) {}
        Person( std::string p_name, std::string p_email, int p_age): name(p_name), email(p_email), age(p_age){}
        Person() : name("Default"), email("default@email.com"), age(0){}

        bool operator>(const Person & other) const{
            return name > other.name;
        }

        bool operator<(const Person & other) const{
            return name < other.name;
        }

        void print() const
        {
            std::cout<< "Person's name: " << name << " and email: " << email << " and age: " << age << std::endl;
        }

        friend bool compare(const Person &first, const Person &second );

};

bool compare(const Person &first, const Person &second )
{
    return first.name < second.name;
};

void printVector(const std::vector<Person> people)
{
    for( auto it = people.begin(); it != people.end(); it++ )
    {
        it->print();
    }
};

int main()
{

    std::vector<Person> people;

    people.push_back(Person("Robert Bob", "robert.bob@gmail.com",27));
    people.push_back(Person("Arthur Toms", "arthur4950@hotmail.com",31));
    people.push_back(Person("Sophien Mathew", "sophie@gmail.com", 18));
    people.push_back(Person("Bruneau Malcon", "bruneauMalcon@outlook.com", 54));

    printVector(people);

    std::sort(people.begin(), people.end(), compare);

    std::cout << "After sorting: " << std::endl;

    printVector(people);



    return 0;
}

