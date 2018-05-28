// Name     : ObjectSlicing.cpp

#include <iostream>

class Parent{
    public:
        Parent()
        {
            std::cout << "Default constructor parent" << std::endl;
        }
        Parent(const Parent &other)
        {
            std::cout << "Copy constructor parent" << std::endl;
        }
        virtual ~Parent()
        {

        }

        virtual void print()
        {
            std::cout << "Parent" << std::endl;
        }
};

class Child : public Parent {
    public:
        void print()
        {
            std::cout << "Child" << std::endl;
        }
};

int main()
{
    
    Child child1;
    Parent &parent1 = child1;
    Parent parent2;
    Parent parent3 = Child();

    child1.print();
    parent1.print();
    parent2.print();
    parent3.print();


    return 0;
}

