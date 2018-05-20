// Name     : Sets.cpp

#include <iostream>
#include <fstream>
#include <set>

const int string_size = 50;


class Person
{
    public:
        std::string name;
        std::string email;
        int age;
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

        void print()
        {
            std::cout<< "Person name: " << name << " and email: " << email << " and age: " << age << std::endl;
        }

};

void savePerson(const std::string fileName, const Person & person)
{
    std::fstream oFile;

    oFile.open( fileName, std::ios::binary|std::ios::out );

    if(oFile.is_open())
    {
        int stringLength = person.name.length() + 1;
        std::cout << "Saving string lenght " << stringLength << std::endl;
        oFile.write(reinterpret_cast<char *>(&stringLength), sizeof(int));
        std::cout << "Saving string" << std::endl;
        oFile.write(person.name.c_str(), sizeof(char[stringLength]));
        stringLength = person.email.length() + 1;
        oFile.write(reinterpret_cast<char *>(&stringLength), sizeof(int));
        oFile.write(person.email.c_str(), sizeof(char[stringLength]));
        int age = person.age;
        oFile.write(reinterpret_cast<char *>(&age), sizeof(int));
        std::cout << "Person saved" << std::endl;

        oFile.close();
    }
    else
    {
        std::cout << "Couldn't read: " + fileName << std::endl;

    }

}

Person loadPerson(const std::string fileName)
{
    std::fstream iFile;

    Person person;

    iFile.open( fileName, std::ios::binary|std::ios::in );

    if(iFile.is_open())
    {
        int stringLength = 0;
        
        iFile.get(reinterpret_cast<char *>(&stringLength), sizeof(int));
        std::cout << "Loading string lenght: " << stringLength << std::endl;
        iFile.get();
        char name[stringLength];
        
        iFile.get(name, sizeof(char[stringLength]));
        std::cout << "Loading name: " << std::string(name) << std::endl;
        iFile.get();
        iFile.get(reinterpret_cast<char *>(&stringLength), sizeof(int));
        std::cout << "Loading string lenght: " << stringLength << std::endl;
        iFile.get();
        char email[stringLength];
        iFile.get(email, sizeof(char[stringLength]));
        std::cout << "Loading email: " << std::string(email) << std::endl;
        iFile.get();
        int age;
        iFile.get(reinterpret_cast<char *>(&age), sizeof(int));
        iFile.get();
        std::cout << "Person Loaded" << std::endl;

        iFile.close();

        person.name = std::string(name);
        person.email = std::string(email);
        person.age = age;
    }
    else
    {
        std::cout << "Couldn't read: " + fileName << std::endl;

    }

    return person;
}

int main()
{

    std::cout << "Person class size: " << sizeof(Person) << std::endl;

    std::set<Person> people;

    Person first = Person("Tomas", "tomasarrufat@gmail.com", 27);

    first.print();

    //people.insert(Person("Tomas", "tomasarrufat@gmail.com", 27));

    savePerson("test.bin", first);

    Person second = loadPerson("test.bin");

    second.print();
    
    return 0;
}

