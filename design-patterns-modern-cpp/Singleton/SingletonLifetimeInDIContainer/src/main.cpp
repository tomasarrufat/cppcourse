#include <iostream>
#include <cstdio>
#include <memory>
#include <map>
#include <boost/lexical_cast.hpp>
#include "di.hpp"


struct Engine
{
    float volume_l = 5.0f;
    int horse_power = 400;

    friend std::ostream& operator<<(std::ostream& os, const Engine& obj)
    {
        return os 
        << "volume: " << obj.volume_l
        << " horse power: " << obj.horse_power;
    }
};

struct ILogger
{
    virtual ~ILogger(){};

    virtual void Log(const std::string& s) = 0;
};

struct ConsoleLogger : ILogger
{
    ConsoleLogger(){};

    void Log(const std::string& s) override {
        std::cout << "LOG: " << s.c_str() << std::endl;
    }
};

struct Car
{
    std::unique_ptr<Engine> engine;
    std::shared_ptr<ILogger> logger;

    Car(std::unique_ptr<Engine> engine, const std::shared_ptr<ILogger>& logger):
        engine{move(engine)}, logger{logger}
        {   
            logger->Log("Making a car");
        }
        
    friend std::ostream& operator<<(std::ostream& os, const Car& obj)
    {
        return os << "Car with engine: " << *obj.engine;
    }
};
struct IFoo
{
    virtual std::string name() = 0;
};

struct Foo : IFoo
{
    static int id;
    Foo() { id++; }

    std::string name() override {
        return "foo " + boost::lexical_cast<std::string>(id);
    }
};

int Foo::id = 0;

struct Bar
{
    std::shared_ptr<IFoo> foo;
};

int main()
{
    auto injector = boost::di::make_injector(
            boost::di::bind<IFoo>().to<Foo>().in(boost::di::singleton)
    );

    auto bar1 = injector.create<std::shared_ptr<Bar>>();
    auto bar2 = injector.create<std::shared_ptr<Bar>>();

    std::cout << bar1->foo->name() << std::endl;
    std::cout << bar2->foo->name() << std::endl;

    auto logger = std::make_shared<ConsoleLogger>();
    auto car = std::make_shared<Car>(std::make_unique<Engine>(), logger);
    auto injector2 = boost::di::make_injector(
            boost::di::bind<ILogger>.to<ConsoleLogger>()
    );
    
    std::cout << *car << std::endl;

    return 0;
}