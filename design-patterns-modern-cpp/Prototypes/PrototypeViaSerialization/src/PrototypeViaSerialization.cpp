#include <iostream>
#include <memory>
using namespace std;

#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

struct Address
{
    string street, city;
    int room;

    Address() {};

    Address(const string &street, const string &city, const int room) : street(street), city(city), room(room){};

    Address(const Address &other) : street(other.street), city(other.city), room(other.room){};

    friend ostream &operator<<(ostream &os, const Address &address)
    {
        os << "street: " << address.street << " city: " << address.city << " room: " << address.room;
    }

private:
    friend class boost::serialization::access;

    template <class archive>
    void serialize(archive & ar, const unsigned int version)
    {
        ar & street;
        ar & city;
        ar & room;
    }
};

struct Contact
{
    string name;
    Address *address;

    Contact(){};

    Contact(const string &name, Address *address) : name(name), address(address){};

    Contact(const Contact &other) : //Copy constructor
                                    name(other.name),
                                    address(new Address{*other.address}){};

    friend ostream &operator<<(ostream &os, const Contact &contact)
    {
        os << "name: " << contact.name << " address: " << *contact.address;
        return os;
    }

private:
    friend class boost::serialization::access;

    template <class archive>
    void serialize(archive & ar, const unsigned int version)
    {
        ar & name;
        ar & address;
    }
};

struct EmployeeFactory
{
    static unique_ptr<Contact> new_main_office_employee(const string &name, int room)
    {
        static Contact mainOfficeEmployee{"", new Address{"123 East Dr", "London", 0}};
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
    auto clone = [](const Contact& c)
    {
        ostringstream oss;
        boost::archive::text_oarchive oa(oss);
        oa << c;
        string s = oss.str();
        cout << s << endl;
        istringstream iss(s);
        boost::archive::text_iarchive ia(iss);
        Contact result;
        ia >> result;
        return result;
    };

    auto john = EmployeeFactory::new_main_office_employee("Jhon Doe", 125);

    auto jane = clone(*john);
    jane.address->room = 126;
    jane.name = "Jane Smith";

    cout << *john << endl
         << jane << endl;
    return 0;
}