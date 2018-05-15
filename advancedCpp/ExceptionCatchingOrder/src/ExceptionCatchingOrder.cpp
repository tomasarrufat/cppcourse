// Name     : ExceptionCatchingOrder.cpp

#include <iostream>
#include <exception>

void goesWrong()
{
    bool error1Detected = false;
    bool error2Detected = true;

    if(error1Detected)
    {
        throw std::bad_alloc();
    }

    if(error2Detected)
    {
        throw std::exception();
    }
}

int main()
{
    try{
        goesWrong();
    }
    catch( std::bad_alloc &e) // We need to catch allways the child exception first and after the parent ones.
    {
        std::cout << "Caught a bad_alloc: " << e.what() << std::endl;
    }
    catch( std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    

    std::cout << "Program still running!" << std::endl;

    return 0;
}

