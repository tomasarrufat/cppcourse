#include <iostream>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <chrono>
#include <thread>
#include <algorithm>
#include <execinfo.h>

const int TABLE_SIZE = 5;
const int PUBLISHED_NUMBERS = 7;
const int POSSIBLE_NUM_MAX = 60;
const int POSSIBLE_NUM_MIN = 1;

template<std::size_t N>
void initArrayWithRandomNumb(int p_array[N], const int min)
{
    int val = min;
    for(int i = 0; i < N; i++)
    {
        p_array[i] = val;
        val++;
    }

    std::random_shuffle(p_array, p_array + N);
}
template<std::size_t N, std::size_t T>
void initializeTable(int p_table[N][N], const int p_array[T])
{
    int count = 0;
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        for(int j = 0; j < TABLE_SIZE;j++)
        {
            p_table[j][i] = p_array[count];
            count++;
        } 
    }
}

template<std::size_t N, std::size_t T>
void shuffleTable(int p_table[N][N], int p_array[T])
{
    std::random_shuffle(p_array, p_array + T);
    int count = 0;
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        for(int j = 0; j < TABLE_SIZE;j++)
        {
            p_table[j][i] = p_array[count];
            count++;
        } 
    }
}

template<std::size_t N>
void printTable(const int p_table[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf(" %02d",p_table[j][i]);
        }
        printf("\n");
    }
}

template<std::size_t N>
void printArray(const int p_array[N])
{
    for(int j = 0; j < N; j++)
    {
        printf(" %02d",p_array[j]);
    }
    printf("\n");
}

bool isInArray(const int * numbers, const int numbersLen, const int number)
{
    for(int i = 0; i < numbersLen; i++)
    {
        if(numbers[i] == number)
            return true;
    }
    return false;
}

template<std::size_t N, std::size_t M>
bool findMatch(const int table[N][N], const int * options)
{
    //Check lines
    int counter = 0;
    for(int i = 0; i < N; i++)
    {
        counter = 0;
        for(int j = 0; j < N; j++)
        {
            if(isInArray(options,M,table[i][j]))
                counter++;
        }
        if( counter == N )
            return true;
    }

    //Check columns
    for(int i = 0; i < N; i++)
    {
        int counter = 0;
        for(int j = 0; j < N; j++)
        {
            if(isInArray(options,M,table[j][i]))
                counter++;
        }
        if( counter == N )
            return true;
    }

    //Check first diagonal
    counter = 0;
    for(int i = 0; i < N; i++)
    {
        if(isInArray(options,M,table[i][i]))
            counter++;
    }
    if( counter == N )
            return true;

    //Check second diagonal
    counter = 0;
    for(int i = 0; i < N; i++)
    {
        if(isInArray(options,M,table[i][N-1-i]))
            counter++;
    }
    if( counter == N )
            return true;

    return false;

}

template<std::size_t M>
void generateOptions(int * options)
{
    //std::random_shuffle(numberPool, numberPool + N);

    for( int i = 0; i < M; i++)
    {
        options[i] = rand() % 60 + 1;
    }
}

template<std::size_t N>
void enterArray(int options[N])
{
    printf("Please enter numbers %d\n", N);
    for(int i = 0; i < N; i++)
    {
        std::cin >> options[i];
    }
}

int main()
{
    int table[TABLE_SIZE][TABLE_SIZE];
    int array[POSSIBLE_NUM_MAX];
    int options[PUBLISHED_NUMBERS];

    initArrayWithRandomNumb<POSSIBLE_NUM_MAX>(array,1);
    initializeTable<TABLE_SIZE,POSSIBLE_NUM_MAX>(table,array);

    printTable<TABLE_SIZE>(table);

    //enterArray<PUBLISHED_NUMBERS>(options);
    //printf("Result = %d\n", findMatch<TABLE_SIZE,PUBLISHED_NUMBERS>(table,options));

    int iterations;
    printf("Please enter number of iterations: ");
    std::cin >> iterations;
    printf("\n");

    int matches = 0;
    
    generateOptions<PUBLISHED_NUMBERS>(options);
    printf("Simulation with the following options: ");
    printArray<PUBLISHED_NUMBERS>(options);

    
    for( int iteration = 0; iteration < iterations; iteration++ )
    {
        //generateOptions<PUBLISHED_NUMBERS>(options);
        shuffleTable<TABLE_SIZE,POSSIBLE_NUM_MAX>(table,array);
        
        if(findMatch<TABLE_SIZE,PUBLISHED_NUMBERS>(table,options))
        {
            matches++;
            printf("Found match!\n");
            printTable<TABLE_SIZE>(table);
            //printArray<PUBLISHED_NUMBERS>(options);
            
        
        }

    }
    printf("From %d iterations forund %d matches \n", iterations, matches);

}

