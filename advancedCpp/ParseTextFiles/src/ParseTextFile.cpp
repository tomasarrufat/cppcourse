// Name     : ioTextFiles.cpp

#include <iostream>
#include <fstream>


int main()
{

    // Write file part
    std::fstream inputFile;

    std::string fileName = "countryData.txt";

    inputFile.open( fileName, std::ios::in);

    if( !inputFile.is_open() )
    {
        std::cout << "Couldn't read file." << std::endl;
        return 1;
    }

    while(inputFile)
    {
        std::string line;
        std::string countryName;

        std::getline(inputFile, line, ' ');
        std::getline(inputFile, line, ':');
        countryName = line;

        std::getline(inputFile, line);

        int population = atoi(line.c_str());

        //inputFile >> std::ws;

        if(!inputFile)
        {
            break;
        }

        std::cout << "The population in " <<  countryName << " is: " << population << std::endl;

    }

    return 0;
};

