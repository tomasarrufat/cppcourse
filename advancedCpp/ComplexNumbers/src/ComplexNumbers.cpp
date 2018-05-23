// Name     : ComplexNumber.cpp

#include <iostream>
#include <exception>

class Complex
{
    private:
        double real;
        double imaginary;

    public:
        Complex(): real(0.0), imaginary(0.0){}
        Complex(const double real, const double imaginary): real(real), imaginary(imaginary) {}
        Complex(const Complex &other): real(other.real), imaginary(other.imaginary) {}

        Complex &operator=(const Complex &other)
        {
            std::cout << "Running copy constructor." << std::endl;
            real = other.real;
            imaginary = other.imaginary;

            return *this;
        }

        friend std::ostream &operator<<( std::ostream &out, const Complex &output );
        friend const Complex operator+(const Complex &lhs, const Complex &rhs);
        friend const Complex operator+(const Complex &lhs, const double &rhs);
        friend const Complex operator-(const Complex &lhs, const Complex &rhs);
        friend const Complex operator-(const Complex &lhs, const double &rhs);
        friend const Complex operator*(const Complex &lhs, const Complex &rhs);
        friend const Complex operator*(const Complex &lhs, const double &rhs);
        friend const Complex operator/(const Complex &lhs, const double &rhs);
        friend const Complex operator/(const Complex &lhs, const Complex &rhs);

};

std::ostream &operator<<( std::ostream &out, const Complex &output )
{
    out << output.real << " " << output.imaginary << "i";
    return out;
};

const Complex operator+(const Complex &lhs, const Complex &rhs)
{
    return Complex( lhs.real + rhs.real, lhs.imaginary + rhs.imaginary ); 
};

const Complex operator+(const Complex &lhs, const double &rhs)
{
    return Complex( lhs.real + rhs, lhs.imaginary ); 
};

const Complex operator-(const Complex &lhs, const Complex &rhs)
{
    return Complex(lhs.real - rhs.real, lhs.imaginary - rhs.imaginary);
};

const Complex operator-(const Complex &lhs, const double &rhs)
{
    return Complex(lhs.real - rhs, lhs.imaginary);
};

const Complex operator*(const Complex &lhs, const Complex &rhs)
{
    // (x + iy)*(u + iv) = (xu - yv) + i(xv + yu)
    double real = lhs.real * rhs.real - lhs.imaginary * rhs.imaginary;
    double imaginary = lhs.real * rhs.imaginary + lhs.imaginary * rhs.real;

    return Complex(real, imaginary);
};

const Complex operator*(const Complex &lhs, const double &rhs)
{
    return Complex(lhs.real * rhs, lhs.imaginary * rhs);
};

const Complex operator/(const Complex &lhs, const double &rhs)
{

    if( rhs < 1E-6 )
    {
        throw std::invalid_argument(std::string('/' + std::to_string(rhs)));
    }

    return Complex(lhs.real / rhs, lhs.imaginary / rhs);
};

const Complex operator/(const Complex &lhs, const Complex &rhs)
{
    // (x + iy)/(u + iv) = (x + iy)*(u - iv) / (u + iv)*(u - iv) = (x + iy)(u + iv) / (uu + vv)
    return ( lhs * rhs ) / ( rhs.real * rhs.real + rhs.imaginary * rhs.imaginary);
};

int main()
{
    Complex a = Complex(4.0,2.0);
    Complex b = Complex(0.0,-3.0);
    Complex c;

    std::cout << "A is: " << a << std::endl;
    std::cout << "B is: " << b << std::endl;
    std::cout << "Addition A + B = " << a + b << std::endl;
    std::cout << "Substraction A - B = " << a - b << std::endl;
    std::cout << "Product A * B = " << a * b << std::endl;
    std::cout << "Divtion A / B = " << a / b << std::endl;
    c = a + b;

    return 0;
}

