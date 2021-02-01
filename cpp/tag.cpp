#include <iostream>
#include <string>
#include <unordered_map>

struct Tag
{
    using name_t        = std::string;
    using tag_map_t     = std::unordered_map<name_t, Tag>;

    name_t              name;
    tag_map_t           children = {};
};

int main(void)
{
    auto foo = Tag{"foo"};
    auto bar = Tag{"bar"};
    foo.children["bar"] = bar;
    std::cout << foo.name << " -> " << foo.children["bar"].name << std::endl;

    return 0;
}
