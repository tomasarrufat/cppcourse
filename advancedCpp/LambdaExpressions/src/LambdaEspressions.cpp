// Name     : LambdaExpressions.cpp

#include <iostream>
#include <functional>

void addExclamation( void (*pfunction)() ){
    pfunction();
    std::cout << "!!!" << std::flush;
};

double operation( double pa, double pb, std::function<double(double,double)> oper){ // double (*oper)(double a, double b)){
    return oper(pa, pb);
};

int main()
{

    const double constant = 2.0;

    auto function1 = [](){
        std::cout << "Hello there calling function1" << std::flush;
    };

    function1();
    std::cout << " called directly from lambda expression." << std::endl;

    addExclamation(function1);
    std::cout << " called from addExclamation function." << std::endl;

    addExclamation([](){ std::cout << "Hello there from lambda expression" << std::flush; });
    std::cout << " called fron addExclamation function." << std::endl;

    auto divide = [=](double a, double b) -> double {
        if( b == 0.0)
            return 0;
        else
            return constant * ( a / b );
    };

    auto multiply = [=](double a, double b) -> double {
        return constant * a * b;
    };

    std::cout << "Trying multiplication 2 * 4 = " << operation(2.0, 4.0, multiply) << std::endl;
    std::cout << "Trying divition 12 / 3 = " << operation(12.0, 3.0, divide) << std::endl;
    


    
    return 0;
}

