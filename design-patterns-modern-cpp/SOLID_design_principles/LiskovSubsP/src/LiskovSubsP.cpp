//Liskov substitution principle
//A parent class object should be substituded by a child object without any problems.
//In this example it does not make sense to derive square from rectangle.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Rectangle
{
protected:
  int _width, _height;
public:
  Rectangle(int width, int height) : _width(width), _height(height) {};

  virtual void setWidth(int width) {
    _width = width;
  }

  virtual void setHeight(int height) {
    _height = height;
  }

  int getWidth() const {
    return _width;
  }

  int getHeight() const {
    return _height;
  }

  int area() const { return _width * _height; }

};

class Square : public Rectangle
{
  public:
  Square(int size) : Rectangle(size, size) {};

  void setWidth(int width) override
  {
    _width = _height = width;
  }
  void setHeight(int height) override
  {
    _width = _height = height;
  }
};

void process(Rectangle& r)
{
  int w = r.getWidth();
  r.setHeight(10);
  std::cout << "Expected area is : " << (w*10) << 
    " we got " << r.area() << std::endl;
};

int main()
{
  Rectangle r(2,5);
  process(r);

  Square sq(5);
  process(sq);
};