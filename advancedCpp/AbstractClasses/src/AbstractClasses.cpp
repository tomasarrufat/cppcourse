// Name     : Sample.cpp

#include <iostream>

class Animal{
    protected:
        double position;
        const speed;
    public:
        Animal() : position(0.0){}
        
        virtual void status() = 0;
        virtual void run() = 0;
};

class Dog : public Animal{

    void status(){
        std::cout << "Wow! My position is: " << position << std::endl;
    }
};

class Cat : public Animal{

    void status(){
        std::cout << "Miau! My position is: " << position << std::endl;
    }

};

int main()
{
    
    return 0;
}

