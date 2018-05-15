// Name     : ioTextFiles.cpp

#include <iostream>
#include <fstream>



int main()
{

    // Write file part
    std::fstream ioFile;

    int numOfLines = 10;

    //Name of output file
    std::string outputFileName = "text.txt";

    ioFile.open( outputFileName, std::ios::out);

    if(ioFile.is_open()){
        ioFile << "We are going to write " << numOfLines << " lines." << std::endl;
        ioFile << "Let's get on it." << std::endl;
        for (int i = 0; i < numOfLines; i++)
        {
            ioFile << "This is line number " << i + 1 << std::endl;
        }
        ioFile.close();
    }
    else{
        std::cout << "Coudn't create the file: " << outputFileName << std::endl;
    }

    //Read file part
    ioFile.open( outputFileName, std::ios::in);

    if(ioFile.is_open()){
        std::cout << "Reading " << outputFileName << " file." << std::endl;
        std::cout << "File content: " << std::endl;

        std::string fileLine;

        while(ioFile)
        {
            std::getline(ioFile, fileLine);
            std::cout << fileLine << std::endl;
        }

        ioFile.close();
    }
    else{
        std::cout << "Coudn't read the file: " << outputFileName << std::endl;
    }



    return 0;
};

