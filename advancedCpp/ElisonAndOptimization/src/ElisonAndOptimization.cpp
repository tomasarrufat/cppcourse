// Name     : Sample.cpp

#include <iostream>
#include <cstring>
#include <vector>

class Test{
    private:
        const int size = 100;
        int * _pBuffer{nullptr};
    public:
        Test(){
            std::cout << "Default constructor" << std::endl;
            _pBuffer = new int[size]{};
        }
        Test(int parameter){
            std::cout << "Parametrized constructor" << std::endl;
            _pBuffer = new int[size]{};
            for(int it = 0; it < size; it++){
                _pBuffer[it] = parameter;
            }
        }
        Test(const Test &other){
            std::cout << "Copy constructor" << std::endl;
            std::memcpy(_pBuffer, other._pBuffer, size * sizeof(int));
        }
        Test(Test &&other){
                std::cout << "Move constructor" << std::endl;
                _pBuffer = other._pBuffer;
                other._pBuffer = nullptr;
        }

        Test &operator=(const Test &other){
            std::cout << "Assigment operator" << std::endl;
            std::memcpy(_pBuffer, other._pBuffer, size * sizeof(int));
            return *this;
        }
        ~Test(){
            std::cout << "Destructor" << std::endl;
            delete [] _pBuffer;
        }

        friend std::ostream &operator<<(std::ostream &out, const Test &other);
};

std::ostream &operator<<(std::ostream &out, const Test &other){
    out << "Hello from test";
    return out;
};

Test getTest(){
    return Test();
};

void checkRef(const Test &value){
    std::cout << "This is an lvalue reference." << std::endl;
};

void checkRef(Test &&value){
    std::cout << "This is an rvalue reference." << std::endl;
};

void displayNumber(const int &value){
    std::cout << "Lvalue number is: " << value << std::endl;
};

void displayNumber(int &&value){
    std::cout << "Rvalue number is: " << value << std::endl;
};

int main()
{   
    Test test1 = getTest();

    std::cout << test1 << std::endl;

    Test &ltest = test1;

    const Test &test3 = getTest();

    Test &&rvalue = getTest();

    checkRef(ltest);
    checkRef(test3);
    checkRef(getTest());
    checkRef(rvalue);
    checkRef(Test());

    int number = 4;

    displayNumber(number++);
    displayNumber(++number);

    std::cout << "Move constructor demostration:" << std::endl;

    std::vector<Test> cont;
    cont.push_back(Test());
    
    return 0;
}

