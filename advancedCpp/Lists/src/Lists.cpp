// Name     : StandardExceptions.cpp

#include <iostream>
#include <list>

void displayList(const std::list<int> &inputList )
{
    std::cout << "Showing list: " << std::endl;

    for( auto it = inputList.begin(); it != inputList.end(); it++)
    {
        std::cout << *it << std::endl;
    }
};


int main()
{

    std::list<int> numbers;

    const int numNumbers = 20;

    for(int i = 1; i < numNumbers; i++)
    {
        numbers.push_back(i);
    }

    numbers.push_front(0);

    displayList(numbers);

    std::cout << "Now we are going to remove the even numbers from the list:" << std::endl;

    auto it = numbers.begin();

    while( it != numbers.end() )
    {
        if( *it % 2 == 0 ) //Check if element is even
        {
            it = numbers.erase(it);
        }
        else
        {
            it++;
        }
    }

    displayList(numbers);

    std::cout << "Finally we are going to add back the even numbers to the list:" << std::endl;

    it = numbers.begin();

    while( it != numbers.end() )
    {
        if( *it % 2 == 1 )
        {
            it = numbers.insert(it, *it - 1);
            it++;
        }
    
        it++;
    }

    displayList(numbers);

    return 0;
}

