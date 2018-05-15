// Name     : StandardExceptions.cpp

#include <iostream>
#include <fstream>

#pragma pack(push, 1) //Preprocessor directive to pack all the data from struct
struct Person {
    char name[50];
    int age;
    double weight;
};
#pragma pack(pop)

int main()
{
    std::cout << "Size of char array " << 50 * sizeof(char) << std::endl;
    std::cout << "Size of int " << sizeof(int) << std::endl;
    std::cout << "Size of double " << sizeof(double) << std::endl;
    std::cout << "Size of Person " << sizeof(Person) << std::endl;

    Person someone = {"Tomas", 27, 73.5};

    std::fstream ioFile;

    std::string fileName = "test.bin";

    // Write file

    ioFile.open( fileName, std::ios::binary|std::ios::out);

    if(ioFile.is_open())
    {
        ioFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));

        ioFile.close();
    }
    else
    {
        std::cout << "Couldn't read: " + fileName << std::endl;
    }

    // Read file

    Person someoneElse = {};

    ioFile.open( fileName, std::ios::binary|std::ios::in);

    if(ioFile.is_open())
    {
        ioFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));

        ioFile.close();
    }
    else
    {
        std::cout << "Couldn't write: " + fileName << std::endl;
    }

    std::cout << "Person's data: " << someoneElse.name << " " << someoneElse.age << " " << someoneElse.weight << std::endl;

    return 0;
}

