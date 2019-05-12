#include <iostream>
using namespace std;

struct Address
{
    string street, city;
    int room;

    Address(const string &street, const string &city, const int room):
        street(street), city(city), room(room) {};

    friend ostream &operator<<(ostream &os, const Address &address)
    {
        os << "street: " << address.street << " city: " << address.city <<
        " room: " << address.room;
    }
};

struct Contact
{
    string name;
    Address* address;

    Contact(const string &name, Address* address):
        name(name), address(address) {};

    friend ostream &operator<<(ostream &os, const Contact &contact)
    {
        os << "name: " << contact.name << " address: " << *contact.address;
        return os;
    }

};

int main()
{

    Contact john{"Jhon Doe",new Address{"123 East Dr", "London", 125}};
    //Contact jane{"Jane Smith", {"123 East Dr", "London", 127}};
    //In case we have to initialize many contacts that all live/work in the same building, 
    //another option is to use john as a prototype.
    auto jane = john;
    jane.name = "Jane Smith";
    jane.address->room = 126;

    cout << john << endl << jane << endl;
    return 0;
}