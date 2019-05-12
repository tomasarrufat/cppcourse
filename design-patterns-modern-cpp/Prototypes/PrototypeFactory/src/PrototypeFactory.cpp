#include <iostream>
#include <memory>
using namespace std;

struct Address
{
    string street, city;
    int room;

    Address(const string &street, const string &city, const int room):
        street(street), city(city), room(room) {};

    Address(const Address &other) :
        street(other.street), city(other.city), room(other.room) {};

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

    Contact(const Contact &other) : //Copy constructor
        name(other.name),
        address( new Address{ *other.address}) {};

    friend ostream &operator<<(ostream &os, const Contact &contact)
    {
        os << "name: " << contact.name << " address: " << *contact.address;
        return os;
    }

};

struct EmployeeFactory
{
    static unique_ptr<Contact> new_main_office_employee(const string &name, int room)
    {
        static Contact mainOfficeEmployee{"",new Address{"123 East Dr", "London", 0}};
        return new_employee(name, room, mainOfficeEmployee);
    }
    private:
    static unique_ptr<Contact> new_employee(const string &name, int room, const Contact &prototype)
    {
         auto result = make_unique<Contact>(prototype);
         result->name = name;
         result->address->room = room;
         return result;
    }
};

int main()
{
    auto john = EmployeeFactory::new_main_office_employee("Jhon Doe", 125);
    auto jane = EmployeeFactory::new_main_office_employee("Jane Smith", 126);

    cout << *john << endl << *jane << endl;
    return 0;
}