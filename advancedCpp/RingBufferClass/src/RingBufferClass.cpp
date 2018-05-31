// Name     : RingBufferClass.cpp

#include "RingBufferClass.h"


//Circular Ring Functions

template<typename T>
void CircularRing<T>::add(T input){
    values[position] = input;

    position++;

    if(position >= size) position = 0;
};


template<typename T>
typename CircularRing<T>::Iterator CircularRing<T>::begin(){
    return Iterator(0, *this);
};

template<typename T>
typename CircularRing<T>::Iterator CircularRing<T>::end(){
    return Iterator(size, *this);
};


template<typename T>
T &CircularRing<T>::operator[](int index) const{
    if( index >= size || index < 0)
    {
        throw std::range_error("Index out of range");
    }
    
    return values[index];
};

//Iterator Functions

template<typename T>
void CircularRing<T>::Iterator::print()
{
    std::cout << "Hello from Iterator " << T() << std::endl;
};

template<typename T>
bool CircularRing<T>::Iterator::operator!=(const CircularRing<T>::Iterator &other)const{
    return position != other.position;
};

template<typename T>
typename CircularRing<T>::Iterator &CircularRing<T>::Iterator::operator++(int){
    position++;
    return *this;
};

template<typename T>
typename CircularRing<T>::Iterator &CircularRing<T>::Iterator::operator++(){
    position++;
    return *this;
};

template<typename T>
T &CircularRing<T>::Iterator::operator*() const{
    return ring[position];
};

template<class T>
void printIterable(T inputs)
{
    for(auto input : inputs)
    {
        std::cout << input << std::endl;
    }
}

int main()
{

    CircularRing<std::string> textRing(4);

    textRing.add("one");
    textRing.add("two");
    textRing.add("three");
    textRing.add("four");
    textRing.add("five");

    for(int i = 0; i < textRing.getSize(); i++)
    {
        std::cout << textRing[i] << std::endl;
    }

    std::cout << "Printing with the c++ 98 iterator for loop" << std::endl;
    
    for( auto it = textRing.begin(); it != textRing.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "Printing with the c++ 11 range based for loop" << std::endl;

    printIterable<decltype(textRing)>(textRing);
        /*
        Expected output:
        five
        two
        three
        four
        */

    return 0;
}

