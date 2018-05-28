// Name     : TemplateClasses.cpp

#include <iostream>

template<class T>
class Test
{
    private:
        T object;
    public:
        Test(T obj): object(obj) {}

        T getObject() const
        {
            return object;
        }

        

};

template<class T>
std::ostream &operator<<(std::ostream &out,const Test<T> &test)
{
    out << test.getObject();
    return out;
}


int main()
{

    Test<double> number(10.0);
    Test<std::string> word("Word");

    std::cout << "Testing template class: " << number << " " << word << std::endl;
    
    return 0;
}

