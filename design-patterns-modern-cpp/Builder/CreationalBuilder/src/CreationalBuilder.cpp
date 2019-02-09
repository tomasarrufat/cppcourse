#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

struct HtmlElement
{
    std::string name, text;
    std::vector<HtmlElement> elements;
    const size_t indent_size = 2;

    HtmlElement() {}

    HtmlElement(const std::string &name, const std::string &text) : name(name), text(text) {}

    std::string str(int indent = 0) const
    {
        bool last_element(elements.size() < 1);
        std::ostringstream oss;
        std::string i(indent_size * indent, ' ');
        if (last_element)
        {
            oss << i << "<" << name << ">";
            if (text.size() > 0)
                oss << text;
            oss << "</" << name << ">" << std::endl;
        }
        else
        {
            oss << i << "<" << name << ">\n";
            if (text.size() > 0)
                oss << std::string(indent_size * (indent + 1), ' ') << text << std::endl;

            for (auto &element : elements)
                oss << element.str(indent + 1);

            oss << i << "</" << name << ">" << std::endl;
        }

        return oss.str();
    }
};

struct HtmlBuilder
{
    HtmlElement root;

    HtmlBuilder(std::string root_name)
    {
        root.name = root_name;
    }

    void add_child(std::string child_name, std::string child_text)
    {
        HtmlElement e{child_name, child_text};
        root.elements.push_back(e);
    }

    std::string str() const { return root.str(); }
};

int main()
{
    auto text = "Hello, to be or not to be?";
    std::string output;
    output += "<p>";
    output += text;
    output += "</p>";
    std::cout << output << std::endl;

    std::string words[] = {"Black", "Green", "Yellow", "Brown", "Orange"};
    std::ostringstream oss;
    oss << "<ul>\n";
    for (auto &w : words)
        oss << "  <li>" << w << "</li>\n";
    oss << "</url>\n";
    std::cout << oss.str();

    HtmlBuilder builder{"ul"};
    for (auto &w : words)
        builder.add_child("list", w);

    std::cout << builder.str() << std::endl;

    return 0;
}