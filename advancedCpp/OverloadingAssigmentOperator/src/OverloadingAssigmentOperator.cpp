// Name     : OverloadingAssigmentOperator.cpp

#include <iostream>

class Test
{
    private:
        int id;
        std::string name;

    public:
        Test(): id(0), name(""){}

        Test(const int id, const std::string name): id(id), name(name){}

        void print() const
        {
            std::cout << "Test object contains: " << id << " : " << name << std::endl;
        }

        const Test &operator=(const Test & other)
        {
            std::cout << "Calling assigment operator of Test class." << std::endl;
            id = other.id;
            name = other.name;
            return *this;
        }

        Test( const Test & other)
        {
            std::cout << "Calling the copy constructor of Test class." << std::endl;
            *this = other;
        }
};

int main()
{

    Test first = Test(10, "Ten");

    Test second;

    second = first;
    second.print();
    first.print();
    Test third = second;
    third.print();

    return 0;
}

