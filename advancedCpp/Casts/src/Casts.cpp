// Name     : Casts.cpp

#include <iostream>

class Parent{
    public:
        virtual void speak(){
            std::cout <<  "Hello I am your father!" << std::endl;
        }
};

class Brother : public Parent{

};

class Sister : public Parent{

};

int main()
{
 
    Parent parent;
    Brother brother;

    double value = 3.1412;

    std::cout << "C style cast: " << (int) value << std::endl;
    std::cout << "C++ constructor type cast: " << int(value) << std::endl;
    std::cout << "Static type cast: " << static_cast<int>(value) << std::endl;

    Parent *pParent = &brother;
    /* Can't do that: Brother *pBrother = &parent;
    or this: Brother *pBrother = pParent;
    So we can use a static_cast cast at compile time */
    Brother *pBrother1 = static_cast<Brother *>(pParent);
    Brother *pBrother2 = static_cast<Brother *>(&parent); // Neveertheless, this could introduce a lot of problems.
    // A better way of doing this:
    Brother *pBrother3 = dynamic_cast<Brother *>(pParent);

    if(pBrother3 == nullptr){
        std::cout << "Invalid cast!" << std::endl;
    }
    else{
        std::cout << "Cast properly done!" << std::endl;
    }

    //We can also use static cast to cast from rvalue to lvalue references
    Parent &&rParent = static_cast<Parent &&>(parent);
    rParent.speak();

    
    return 0;
}

