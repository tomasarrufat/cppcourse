// Name     : FunctionPointersExample.cpp

#include <iostream>
#include <algorithm>
#include <vector>

void testPrint(std::string input)
{
    std::cout << "Hello " << input << std::endl;
}

bool matchLength(const std::string input, int lenght)
{
    return input.size() == lenght;
};

int countStrings(const std::vector<std::string> &words, int length, bool (*matchf)(const std::string test, int length))
{
    int count = 0;

    for(auto it = words.begin(); it != words.end(); it++ )
    {
        if(matchf(*it, length))
        {
            count++;
        }
    }

    return count;
};

int main()
{
    std::vector<std::string> texts;

    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("four");
    texts.push_back("five");
    texts.push_back("six");
    texts.push_back("seven");
    texts.push_back("eight");

    for(int it = 1; it < 6; it++)
    {
        //size = it;
        //int found = std::count_if(texts.begin(), texts.end(), matchLength);
        int found = countStrings(texts, it, matchLength);
        std::cout << "Number of words found with " << it << " letter(s) is: " << found << std::endl;
    }

    return 0;
}

