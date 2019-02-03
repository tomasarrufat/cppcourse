//Open/Closed Principle Demonstration
//Open for expansion and closed for modification
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum class Color
{
  red,
  green,
  blue,
  brown,
  orang
};
enum class Size
{
  small,
  medium,
  large
};

struct Product
{
  std::string name;
  Color color;
  Size size;
};

class ProductFilter
{

public:
  std::vector<Product *> by_color(std::vector<Product *> items, Color color)
  {
    std::vector<Product *> result;
    for (auto &i : items)
    {
      if (i->color == color)
        result.push_back(i);
    }
    return result;
  }

  std::vector<Product *> by_size(std::vector<Product *> items, Size size)
  {
    std::vector<Product *> result;
    for (auto &i : items)
    {
      if (i->size == size)
        result.push_back(i);
    }
    return result;
  }

  std::vector<Product *> by_size_and_color(std::vector<Product *> items, Size size, Color color)
  {
    std::vector<Product *> result;
    for (auto &i : items)
    {
      if (i->size == size && i->color == color)
        result.push_back(i);
    }
    return result;
  }
  //This is not a very good approach because it doesn't scale well. The more properties and conditions the harder it gets.
};

struct ProductDisplay
{
  static void display(std::vector<Product *> items, std::string message)
  {
    for (auto &item : items)
    {
      std::cout << item->name << message << std::endl;
    }
  }
};

template <typename T>
class Specification
{
public:
  virtual bool is_satisfied(T *item) const = 0;
};

template <typename T>
class Filter
{
public:
  virtual std::vector<T *> filter(std::vector<T *> items, Specification<T> &spec) = 0;
};

class BetterFilter : public Filter<Product>
{
public:
  std::vector<Product *> filter(std::vector<Product *> items, Specification<Product> &spec) override
  {
    std::vector<Product *> result;
    for (auto &item : items)
    {
      if (spec.is_satisfied(item))
        result.push_back(item);
    }
    return result;
  };
};

class ColorSpecification : public Specification<Product>
{
private:
  Color color;

public:
  ColorSpecification(Color color) : color(color){};

  bool is_satisfied(Product *item) const override
  {
    return item->color == color;
  }
};

class SizeSpecification : public Specification<Product>
{
private:
  Size size;

public:
  SizeSpecification(Size size) : size{size} {};

  bool is_satisfied(Product *item) const override
  {
    return item->size == size;
  }
};

template <typename T>
class AndSpecification : public Specification<T>
{
private:
  const Specification<T> &first;
  const Specification<T> &second;

public:
  AndSpecification(const Specification<T> &first, const Specification<T> &second) : first{first}, second{second} {};

  bool is_satisfied(T *item) const override
  {
    return first.is_satisfied(item) && second.is_satisfied(item);
  }
};

template <typename T>
AndSpecification<T> operator&&(const Specification<T> &first, const Specification<T> &second)
{
  return AndSpecification<T>(first, second);
}

int main()
{
  Product apple{"Apple", Color::green, Size::small};
  Product tree{"Tree", Color::green, Size::large};
  Product house{"House", Color::blue, Size::large};

  std::vector<Product *> items{&apple, &tree, &house};

  ProductFilter ft;
  auto green_things = ft.by_color(items, Color::green);

  for (auto &i : green_things)
  {
    std::cout << i->name << " is green" << std::endl;
  }

  auto green_large_things = ft.by_size_and_color(items, Size::large, Color::green);

  for (auto &i : green_large_things)
  {
    std::cout << i->name << " is green and large" << std::endl;
  }

  BetterFilter bf;
  ColorSpecification green(Color::green);
  SizeSpecification large(Size::large);
  auto green_large_spec = green && large;

  std::cout << "Trying out BetterFilter: \n";
  ProductDisplay::display(bf.filter(items, green_large_spec), std::string(" is green and large."));

  return 0;
};
