// Name     : RingBufferClass.h

#include <iostream>
#include <exception>
#include <initializer_list>
#include <memory>
#include <cstring> // std::memcpy

template<typename T>
class CircularRing
{
    private:
        int position;
        const int size;
        std::unique_ptr<T[]> values;
    public:
        class Iterator;

    public:
        CircularRing(int size): position(0), size(size), values(new T[size]{}){};
        CircularRing(const CircularRing &other): position(other.position),
            size(other.size), values(new T[size]{}){
                for(int it = 0; it < size; it++)
                {
                    values.get()[it] = other.values.get()[it];
                }
                //std::memcpy(values.get(), other.values.get(), size * sizeof(T));
                //std::copy(other.values[0], other.values[size-1], values[0]);
                std::cout << "Making copy of circular ring." << std::endl;
            };

        ~CircularRing(){
            std::cout << "CircularRing destroyed" << std::endl;
        };

        void add(T input);
        void add(std::initializer_list<T> inputs);

        Iterator begin() const;
        Iterator end() const;

        int getSize() const { return size; }

        T &operator[](int index) const;
};

template<typename T>
class CircularRing<T>::Iterator
{
    private:
        int position;
        const CircularRing<T> &ring;

    public:
        Iterator(int pos, const CircularRing<T> &aRing): position(pos), ring(aRing){};
        bool operator!=(const CircularRing<T>::Iterator &other)const;
        Iterator &operator++(int);
        Iterator &operator++();
        T &operator*() const;
        void print();
};

