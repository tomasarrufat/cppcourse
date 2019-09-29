#include <iostream>
#include <vector>

/*
A Composite: is a mechanism for treating individual (scalar) objects and compositions of objects
in a uniform manner.
*/

struct GraphicObject
{
    virtual void draw() = 0;
};

struct Circle : GraphicObject
{
    void draw() override {
        std::cout << "Circle" << std::endl;
    };
};

struct Group : GraphicObject
{
    std:: string name;
    std::vector<GraphicObject *> objects;

    Group(const std::string &name) : name(name){};

    void draw() override {
        std::cout << "Group " << name.c_str() << " contains: " << std::endl;
        for (auto&& o : objects)
            o->draw();
    }
};

int main()
{
    Group root("root");
    Circle c1, c2;
    root.objects.push_back(&c1);

    Group supgroup("sub");
    supgroup.objects.push_back(&c2);

    root.objects.push_back(&supgroup);

    root.draw();
}