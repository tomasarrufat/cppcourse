// Name     : NestedTemplateClasses.cpp

#include <iostream>
#include <vector>

template <class T>
class CircularRing
{
    private:
        int size;
        int addPos;
        bool full;
        std::vector<T> data;
    public:
        CircularRing() : size(0), addPos(0), full(false) {
            data.reserve(size);
        }

        CircularRing( int size ) : size(size), addPos(0), full(false) {
            data.reserve(size);
        }

        CircularRing( CircularRing &other){
            size = other.size;
            addPos = other.addPos;
            full = other.full;
            data = other.data;
        }

        void add(T input)
        {
            if(full)
            {
                if(addPos < size)
                {
                    data[addPos] = input;
                    addPos++;
                }
                else
                {
                    data[0] = input;
                    addPos = 1;
                }

            }
            else
            {
                data.push_back(input);
                addPos++;
                full = addPos >= size;
            }
        }

        T get(int i)
        {
            return data[i];
        }

        int getSize()
        {
            return size;
        }

};

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
            std::cout << textRing.get(i) << std::endl;
        }
        /*
        Expected output:
        five
        two
        three
        four
        five
        */

    return 0;
}

