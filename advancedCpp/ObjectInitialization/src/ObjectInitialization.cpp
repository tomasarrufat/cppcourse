// Name     : ObjectInitialization.cpp

#include <iostream>

class Test{
    private:
        int age{10};
        std::string name{"Default1"};
    public:
        Test() = default;
        Test(int age, std::string name):age(age), name(name){};
        Test(const Test& other ) = delete;
        int getAge() const { return age; };
        std::string getName() const { return name; };
        void print() const {
            std::cout << "Name is: " << name << " and age is: " << age << std::endl;
        };
};

int main()
{
    Test t1;
    t1.print();

    Test t2(25, "Ernesto");
    t2.print();

    /*
    Can't use copy constructor because it has been = delete;(d)
    Test t3{t1};
    t3.print();
    */




    return 0;
}

