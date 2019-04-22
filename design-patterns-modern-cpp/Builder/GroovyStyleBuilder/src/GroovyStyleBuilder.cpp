#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

#include <iostream>

struct Tag
{
    std::string name, text;
    std::vector<Tag> children;
    std::vector<std::pair<std::string, std::string>> attributes;

    friend std::ostream &operator<<(std::ostream &os, const Tag &tag)
    {
        os << "<" << tag.name;

        for (const auto &att : tag.attributes)
            os << " " << att.first << "=\"" << att.second << "\"";

        if (tag.children.size() == 0 && tag.text.length() == 0)
        {
            os << "/>" << std::endl;
        }
        else
        {
            os << ">" << std::endl;

            if (tag.text.length())
                os << tag.text << std::endl;

            for (const auto &child : tag.children)
                os << child;

            os << "</" << tag.name << ">" << std::endl;
        }

        return os;
    }

  protected:
    Tag(const std::string &name, const std::string &text) : name(name), text(text) {}

    Tag(const std::string &name, const std::vector<Tag> &children) : name(name), children(children) {}

    
};

struct Paragraph : Tag
{
     Paragraph(const std::string &text) : Tag("p", text) {};
     Paragraph(std::initializer_list<Tag> children) : Tag("p", children) {}
};

struct Image : Tag
{
 explicit Image(const std::string  &url) : Tag{ "img", ""}
 {
     attributes.emplace_back(std::make_pair("src", url));
 }
};

int main()
{
    std::cout << 
        Paragraph {
            Image { "http://pokemon.com/pikachu.png"}
        }
        << std::endl;
    return 0;
}