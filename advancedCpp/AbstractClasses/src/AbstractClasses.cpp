// Name     : Sample.cpp

#include <iostream>
#include <memory>
#include <array>

class Animal{
    protected:
        double _position;
        double _speed;
    public:
        Animal(double pos, double speed) : _position(pos), _speed(speed) {};
        
        virtual double status() = 0;
        void run(){
            _position += _speed;
        };
};

class Dog : public Animal{

    public:
    Dog() : Animal(0., 5.){};

    double status(){
        std::cout << "Wow! My position is: " << _position << std::endl;
        return _position;
    }
};

class Cat : public Animal{

    public:
    Cat () : Animal(0., 6.){};

    double status(){
        std::cout << "Miau! My position is: " << _position << std::endl;
        return _position;
    }

};

bool checkIfFinished(Animal * animals[], const int numAnimals, const double race_lenght){
    bool finished = false;
    for(auto i = 0; i < numAnimals; i++)
    {
        if( animals[i]->status() > race_lenght ) finished = true;
    }
    return finished;
}

void printPointers(int * pointers[])
{
    std::cout << "Within printPointers function" << std::endl;
    std::cout<< "pointer[0] is = "<< pointers[0] << std::endl;
    std::cout<< "dereferenced pointer[0] is = " << *pointers[0] << std::endl;
}

int main()
{
    const int lenght = 2;
    Animal * animals[lenght];
    Dog doggie;

    int a = 23;
    int * b;
    std::cout<< "a is = "<< a << std::endl;
    std::cout<< "b is = "<< b << std::endl;
    b = &a;
    std::cout<< "b is = "<< b << std::endl;
    std::cout<< "dereferenced b is = " << *b << std::endl;
    std::cout<< "Now with arrays" << std::endl;

    int * c[3];
    c[0] = b;
    std::cout<< "c[0] is = " << c[0] << std::endl;
    std::cout<< "dereferenced c[0] is = " << *c[0] << std::endl;

    printPointers(c);
    Cat cat = Cat();
    animals[0] = new Cat();
    animals[1] = new Dog();

    animals[0]->status();
    animals[1]->status();
    //[1] = &Dog::Dog();

    const double race_lenght {100.};

    checkIfFinished(animals, lenght, race_lenght);

    while(!checkIfFinished(animals, lenght, race_lenght))
    {
        animals[0]->run();
        animals[1]->run();
    }


    return 0;
}

 