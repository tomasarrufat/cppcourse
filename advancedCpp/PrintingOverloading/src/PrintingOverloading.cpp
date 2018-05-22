// Name     : PrintingOverloading.cpp

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

        friend std::ostream &operator<<( std::ostream &out, const Test &test )
        {
            out << test.id << " : " << test.name;
            return out;
        }
};

int main()
{

    Test first = Test(10, "Ten");
    Test second = Test(20, "Twenty");

    std::cout << first << " " << second << std::endl;

    return 0;
}


