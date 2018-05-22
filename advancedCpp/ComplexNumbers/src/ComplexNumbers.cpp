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

        Complex &operator+(const Complex &other)
        {
            real += other.real;
            imaginary += other.imaginary;

            return *this; 
        }

        Complex &operator+(const double &other)
        {
            real += other;

            return *this; 
        }

        Complex &operator-(const Complex &other)
        {
            real -= other.real;
            imaginary -= other.imaginary;
            
            return *this;
        }

        Complex &operator-(const double &other)
        {
            real -= other;
            
            return *this;
        }

        Complex &operator*(const Complex &other)
        {
            // (x + iy)*(u + iv) = (xu - yv) + i(xv + yu)
            real = real * other.real - imaginary * other.imaginary;
            imaginary = real * other.imaginary + imaginary * other.real;

            return * this;
        }

        Complex &operator*(const double &other)
        {
            real = real * other;
            imaginary = imaginary * other;

            return * this;
        }

        Complex &operator/(const double &other)
        {

            if( other < 1E-6 )
            {
                throw std::invalid_argument(std::string('/' + std::to_string(other)));
            }
            else
            {
                real = real / other;
                imaginary = imaginary / other;
            }

            return * this;
        }

        Complex &operator/(const Complex &other)
        {
            // (x + iy)/(u + iv) = (x + iy)*(u - iv) / (u + iv)*(u - iv) = (x + iy)(u + iv) / (uu + vv)
            *this = ( (*this) * other ) / ( other.real * other.real + other.imaginary * other.imaginary);

            return *this;
        }
};

int main()
{
    
    return 0;
}

