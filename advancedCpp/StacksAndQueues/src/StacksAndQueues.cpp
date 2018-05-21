// Name     : StacksAndQueues.cpp

#include <iostream>
#include <stack>
#include <queue>



class Test
{
    private:
        std::string name;
    public:

        Test(std::string pname): name(pname) {}

        ~Test()
        {
            std::cout << "Object of class Test destroyed." << std::endl;
        }

        void print() const
        {
            std::cout << "Test name is: " << name << std::endl;
        }
};

int main()
{
    std::stack<Test> testStack;

    testStack.push(Test("Mike"));
    testStack.push(Test("John"));
    testStack.push(Test("Tony"));
    testStack.push(Test("Ford"));

    std::cout << std::endl;

    while( testStack.size() > 0)
    {
        Test &test = testStack.top();
        test.print();
        testStack.pop();
    }

    std::queue<Test> testQueue;

    testQueue.push(Test("Mike"));
    testQueue.push(Test("John"));
    testQueue.push(Test("Tony"));
    testQueue.push(Test("Ford"));

    std::cout << std::endl;

    while( testQueue.size() > 0)
    {
        Test &test = testQueue.front();
        test.print();
        testQueue.pop();
    }
    
    return 0;
}

