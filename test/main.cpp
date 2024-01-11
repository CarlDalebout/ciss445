#include <iostream>
#include <string>
#include <vector>

struct Node
{
    std::string     tok;
    int             type;
};

int main()
{
    std::vector<Node> vec;
    vec.push_back({"test1", 1});
    vec.push_back({"test2", 2});
    vec.push_back({"test3", 3});
    vec.push_back({"test4", 4});
    for(int i = 0; i < vec.size(); ++i)
    {
        std::cout << "Tok: \"" << vec[i].tok << "\" Type: " << vec[i].type << "\n";
    }
    return 0;
}