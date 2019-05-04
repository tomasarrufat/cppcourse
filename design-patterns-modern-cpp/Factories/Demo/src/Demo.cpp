#define _USE_MATH_DEFINES
#include <string>
#include <iostream>
#include <cmath>
#include <utility>

enum class PointType
{
    cartesian,
    polar
};
class Point
{
    //friend class PointFactory;

    Point(float x, float y) : x(x), y(y){};

    float x, y;

public:
    friend std::ostream &operator<<(std::ostream &os, const Point &point)
    {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }

    class PointFactoy
    {
    public:
        static Point NewCartesian(float x, float y)
        {
            return {x, y};
        };

        static Point NewPolar(float r, float theta)
        {
            return {r * std::cos(theta), r * std::sin(theta)};
        };
    };
};

int main()
{
    auto p = Point::PointFactoy::NewPolar(5., M_PI_4);

    std::cout << p << std::endl;

    return 0;
}