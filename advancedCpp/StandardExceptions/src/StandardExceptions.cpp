// Name     : StandardExceptions.cpp

#include <iostream>
using namespace std;

class CanGoWrong {

    public:
        CanGoWrong() {
            char *pMemory = new char[99999999999999999];
            delete[] pMemory;
        }
};

int main()
{
    try{
        CanGoWrong wrong;
    }
    catch( bad_alloc & e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }

    cout << "Program still running!" << endl;

    return 0;
}

