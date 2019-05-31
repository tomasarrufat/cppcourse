#include <iostream>
#include <fstream>
#include <memory>
#include <map>
#include <boost/lexical_cast.hpp>

class Printer
{
    static int id;
    public:
    int get_id() const { return id; }
    void set_id(int value) {id = value; }
};

int Printer::id;

int main()
{
    Printer p1;
    p1.set_id(1);

    Printer p2;
    p2.set_id(2);

    std::cout << "Printer 1 has id: " << p1.get_id()
        << " Printer 2 has id: " << p2.get_id() << std::endl;

    return 0;
}