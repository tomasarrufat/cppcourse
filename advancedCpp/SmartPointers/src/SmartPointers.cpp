// Name     : Sample.cpp

#include <iostream>
#include <memory>
#include <cstring>

class Test{
    int number = 0;
    public:
        Test(){
            std::cout << "Constructor call." << std::endl;
        }
        Test(int pNumber): number(pNumber){
            Test();
        }
        ~Test(){
            std::cout << "Destructor call of object with number: " << number << std::endl;
        }
        void show(){
            std::cout << "The number is: " << number << std::endl;
        }
        void change(int pNumber){
            number = pNumber;
        }
};

int main()
{
    Test * pTest = new Test();
    std::unique_ptr<Test[]> pSmartTest1(new Test[2]);
    pSmartTest1[0].change(1);
    pSmartTest1[1].change(2);

    delete pTest;

    pSmartTest1[0].show();
    pSmartTest1[1].show();
    std::unique_ptr<Test[]> pSmartTest2(new Test[2]);
    std::memcpy(pSmartTest2.get(), pSmartTest1.get(), 2 * sizeof(Test));
    pSmartTest1[0].change(20);

    pSmartTest1[0].show();
    pSmartTest1[1].show();
    pSmartTest2[0].show();
    pSmartTest2[1].show();
    
    //Shared pointers section
    
    std::shared_ptr<Test> pShared1(nullptr);
    std::cout <<  "First shared pointer initialized to null." << std::endl;

    {
        std::shared_ptr<Test> pShared2 = std::make_shared<Test>(55);
        std::cout << "Second shared pointer initialized with number 55." << std::endl;

        pShared1 = pShared2;
        
        std::cout << "First shared pointer is the same as second shared pinter." << std::endl;

        std::cout << "Second shared pointer is going out of scope." << std::endl;
    }

    std::cout << "Nothing destoyed yet. Now the first pointer also will go out of scope. Expected destructuon!" << std::endl;
    return 0;
}

