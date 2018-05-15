// Name     : BasicExceptions.cpp

#include <iostream>
using namespace std;

void mightGoWrong()
{
    bool error1 = false;
    bool error2 = true;

    if(error1)
        throw "Something went wrong.";

    if(error2)
        throw string("Something else went wrong.");
}

int main()
{

    try{
    mightGoWrong();
    }
    catch(int e){
        cout << "Error code: " << e << endl; 
    }
    catch(char const * e){
        cout << "Error message: " << e << endl;
    }
    catch(string &e)
    {
        cout << "string error message: " << e << endl;
    }

    cout << "Still running!" << endl;

    return 0;
}

