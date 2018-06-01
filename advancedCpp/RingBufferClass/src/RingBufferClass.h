// Name     : RingBufferClass.h

#include <iostream>
#include <exception>
#include <initializer_list>

template<typename T>
class CircularRing
{
    private:
        int position;
        const int size;
        T * values;
    public:
        class Iterator;

    public:
        CircularRing(int size): position(0), size(size), values(0){
            values = new T[size];
        }

        ~CircularRing(){
            delete [] values;
        }

        void add(T input);
        void add(std::initializer_list<T> inputs);

        Iterator begin();
        Iterator end();

        int getSize() const { return size; }

        T &operator[](int index) const;
};

template<typename T>
class CircularRing<T>::Iterator
{
    private:
        int position;
        CircularRing<T> &ring;

    public:
        Iterator(int pos, CircularRing<T> &aRing): position(pos), ring(aRing){};
        bool operator!=(const CircularRing<T>::Iterator &other)const;
        Iterator &operator++(int);
        Iterator &operator++();
        T &operator*() const;
        void print();
};

