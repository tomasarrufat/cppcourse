#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include "Config.h"

// A. High-level modules should not depend on low-level modules.
//    Both should depend on abstractions.
// B. Abstractions should not depend on details.
//    Details should depend on abstractions.

enum class Relationship
{
  parent,
  child,
  sibling
};

struct Person
{
  std::string name;
};

#ifdef USE_PRINCIPLE
struct RelationshipBrowser
{
  virtual std::vector<Person> find_all_children_of(const std::string &name) = 0;
};

struct Relationships : RelationshipBrowser // low-level
#else
struct Relationships // low-level
#endif
{
  std::vector<std::tuple<Person, Relationship, Person>> relations;

  void add_parent_and_child(const Person &parent, const Person &child)
  {
    relations.push_back({parent, Relationship::parent, child});
    relations.push_back({child, Relationship::child, parent});
  }

#ifdef USE_PRINCIPLE
  std::vector<Person> find_all_children_of(const std::string &name)
  {
    std::vector<Person> result;

    for (auto &&[first, relation, second] : relations)
    {
      if (first.name == name && relation == Relationship::parent)
      {
        result.push_back(second);
      }
    }
    return result;
  };
#endif
};

struct Research // high-level
{
#ifdef USE_PRINCIPLE
  Research(RelationshipBrowser &browser)
  {
    std::cout << "Using dependency inversion principle" << std::endl;
    for (auto &child : browser.find_all_children_of("John"))
    {
      std::cout << "John has a chid named: " << child.name << std::endl;
    }
  }
#else
  Research(Relationships &relationships)
  {
    std::cout << "Not using dependency inversion principle" << std::endl;
    auto &relations = relationships.relations;
    for (auto &&[first, rel, second] : relations)
    {
      if (first.name == "John" && rel == Relationship::parent)
      {
        std::cout << "John has a child named: " << second.name << std::endl;
      }
    }
  }
#endif
};

int main()
{
  Person parent{"John"};
  Person child1{"Chris"}, child2{"Jessica"};

  Relationships relationships;
  relationships.add_parent_and_child(parent, child1);
  relationships.add_parent_and_child(parent, child2);

  Research _(relationships);

  return 0;
};