// Name     : Sets.cpp

#include <iostream>
#include <fstream>
#include <set>


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

        void print() const
        {
            std::cout<< "Person's name: " << name << " and email: " << email << " and age: " << age << std::endl;
        }

};

void savePersons(const std::string fileName, const std::set<Person> & persons)
{
    std::fstream oFile;

    oFile.open( fileName, std::ios::binary|std::ios::out );

    if(oFile.is_open())
    {
        int mapSize = persons.size();
        oFile.write(reinterpret_cast<char *>(&mapSize), sizeof(int));

        for( auto person = persons.begin(); person != persons.end(); person++ )
        {
            std::cout << "Saving person " << person->name << std::endl;
            int stringLength = person->name.length() + 1;
            //std::cout << "Saving string lenght " << stringLength << std::endl;
            oFile.write(reinterpret_cast<char *>(&stringLength), sizeof(int));
            //std::cout << "Saving string" << std::endl;
            oFile.write(person->name.c_str(), sizeof(char[stringLength]));
            stringLength = person->email.length() + 1;
            oFile.write(reinterpret_cast<char *>(&stringLength), sizeof(int));
            oFile.write(person->email.c_str(), sizeof(char[stringLength]));
            int age = person->age;
            oFile.write(reinterpret_cast<char *>(&age), sizeof(int));
            //std::cout << "Person saved" << std::endl;
        }

        oFile.close();
    }
    else
    {
        std::cout << "Couldn't read: " + fileName << std::endl;
    }

}

void loadPersons(const std::string fileName, std::set<Person> &persons )
{
    std::fstream iFile;

    iFile.open( fileName, std::ios::binary|std::ios::in );

    if(iFile.is_open())
    {
        int mapSize = 0;
        iFile.get(reinterpret_cast<char *>(&mapSize), sizeof(int));
        iFile.get();

        for(int i = 0; i < mapSize; i++)
        {
            std::cout << "Loading person " << std::flush;
            int stringLength = 0;

            iFile.get(reinterpret_cast<char *>(&stringLength), sizeof(int));
            iFile.get();
            char name[stringLength];

            iFile.get(name, sizeof(char[stringLength]));
            std::cout << std::string(name) << std::endl;
            iFile.get();
            iFile.get(reinterpret_cast<char *>(&stringLength), sizeof(int));
            iFile.get();
            char email[stringLength];
            iFile.get(email, sizeof(char[stringLength]));
            iFile.get();
            int age;
            iFile.get(reinterpret_cast<char *>(&age), sizeof(int));
            iFile.get();

            persons.insert(Person(std::string(name),std::string(email),age));
        }
        iFile.close();
    }
    else
    {
        std::cout << "Couldn't read: " + fileName << std::endl;
    }
}

void printSet(const std::set<Person> inputs)
{
    for( auto input = inputs.begin(); input != inputs.end(); input++ )
    {
        input->print();
    }
}

int main()
{

    std::cout << "Person class size: " << sizeof(Person) << std::endl;

    std::set<Person> people;

    people.insert(Person("Tomas", "tomasarrufat@gmail.com", 27));
    people.insert(Person("Yuri", "clairejang@gmail.com", 27));

    savePersons("test.bin", people);

    std::set<Person> loadedPeople;

    loadPersons("test.bin", loadedPeople);

    printSet(loadedPeople);
    
    return 0;
}

//Add Found functionality

