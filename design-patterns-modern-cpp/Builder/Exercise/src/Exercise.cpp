#include <string>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class CodeBuilder
{

private:
    string className;
    vector<pair<string, string>> members;
    
public:
  CodeBuilder(const string& class_name): className(class_name)
  {
      // todo
  }

  CodeBuilder& add_field(const string& name, const string& type)
  {
      members.emplace_back(make_pair(type, name));
    return *this;
  }

  friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
  {
    os << "Class " << obj.className << endl;
    os << "{" << endl;
    for( auto member : obj.members )
    {
        os << "     " << member.first << " " << member.second << ";" << endl;
    }
    os << "}" << endl;

    return os;
  }
};

int main()
{
    auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
    cout << cb;
    return 0;
}