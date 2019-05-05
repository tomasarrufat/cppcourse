#include <string>
#include <list>
#include <iostream>
using namespace std;

struct Person
{
  int id;
  string name;
};

class PersonFactory
{
    int ids = 0;
public:
  Person create_person(const string& name)
  {
      Person person = Person{ids, name};
      ids++;
      return person;
  }
};

int main()
{
    PersonFactory pf;

    list<Person> persons;
    persons.push_back(pf.create_person("Person1"));
    persons.push_back(pf.create_person("Person2"));

    for( auto person : persons)
    {
        cout << "Person with name: " << person.name << " and Id: " << person.id << endl;
    }

    return 0;
}