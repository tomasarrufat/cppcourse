// Name     : CustomExceptions.cpp

#include <iostream>
#include <exception>

using namespace std;

class Base{ virtual void member(){} };

class Derived : Base {};

class MyException : public exception {

    public:
        virtual const char* what() const throw(){ // const throw means that this method can't throw an exception
            return "Something whent wrong";
        };
};

class Test{
    public:
        void goesWrong(){
            throw MyException();
        }

        void moreStuffGoesWrong(){
            Derived& d = dynamic_cast<Derived&>(b);
        }

    private:
        Base b;

};


int main()
{
    Test test;

    try{
        test.moreStuffGoesWrong();
    }
    catch(MyException & e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }
    catch(bad_cast & bc)
    {
        cout << "Caught bad cast exception: " << bc.what() << endl;
    }

    return 0;
}

