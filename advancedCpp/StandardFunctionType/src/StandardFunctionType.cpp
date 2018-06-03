// Name     : StandardFunctionType.cpp

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

bool check( std::string &input ){
    return input.size() == 3;
};

class Test{
    public:
    bool operator()( std::string &input){
        return input.size() == 3;
    }
};

template<class T>
void printIterable(T inputs)
{
    for(auto input : inputs)
    {
        std::cout << input << std::endl;
    }
};

template<class T>
int ownCountIf(T inputs, std::function<bool(std::string&)> check ){

    int counter = 0;

    for(auto input : inputs)
    {
        if(check(input))
            counter++;
    }

    return counter;
};

int main()
{
    
    std::vector<std::string> numbers{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    printIterable<decltype(numbers)>(numbers);
    std::cout << "Input the size of word to count: ";
    int searchSize;
    std::cin >> searchSize;

    int count = std::count_if(numbers.begin(), numbers.end(), [searchSize](std::string input){ return input.size() == searchSize;});

    std::cout << "Number of words with "<< searchSize << " letters is: " << count << std::endl;

    std::cout << "Now testing the same with a function pointer and a functor for a value of 3:" << std::endl;

    count = std::count_if(numbers.begin(), numbers.end(), check);

    std::cout << "Number of words with 3 letters is: " << count << std::endl;

    Test condition;

    count = std::count_if(numbers.begin(), numbers.end(), condition);

    std::cout << "Number of words with 3 letters is: " << count << std::endl;

    std::cout << std::endl;

    std::cout << "Now testing my own count if function:" << std::endl;

    count = ownCountIf<decltype(numbers)>(numbers, [searchSize](std::string input){ return input.size() == searchSize;});

    std::cout << "Number of words with "<< searchSize << " letters is: " << count << std::endl;

    std::cout << "Now testing the same with a function pointer and a functor for a value of 3:" << std::endl;

    count = ownCountIf<decltype(numbers)>(numbers, check);

    std::cout << "Number of words with 3 letters is: " << count << std::endl;

    count = ownCountIf<decltype(numbers)>(numbers, condition);

    std::cout << "Number of words with 3 letters is: " << count << std::endl;

    return 0;
}

