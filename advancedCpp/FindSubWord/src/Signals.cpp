#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <chrono>
#include <thread>
#include <memory>
#include <execinfo.h>

bool containsSubString(const char * pString, const int stringl, const char * pSubStr, const int substrl)
{
    int counter = 0;

    for(int i = 0; i  < (stringl - substrl + 1); i++)
    {
        counter = 0;
        for(int j = 0; j < substrl;j++)
        {
            printf("Assessing char %c \n", pString[i + j]);
            if(pString[i + j] == pSubStr[j])
            {
                counter++;
                printf("Found match for index i %d and j %d with char %c \n", i, j, pString[i + j]);
            }
        }

        if (counter == substrl)
            return true;
    }

    return false;
};

int main()
{
    char word[] = {'H','e','l','l','o',' ','w','o','r','l','d'};
    int wordl = 0;
    char sub[] = {'w','o','r','l','l'};
    int subl = 5;
    printf("Result of assessment is %d\n",containsSubString(word,wordl,sub, subl) );
    return 0;
}

