#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include "TokenList.h"
#include "P.h"

int main()
{
    std::string user_input = " ";
    std::string seperators = " \t";
    TokenList tokens(user_input, seperators);
    P p;
    while(!user_input.empty())
    {
        tokens.clear();
        std::cout << ">>> ";
        std::getline(std::cin, user_input);
        tokens.push_back(user_input);
        p.eval_input(tokens);
        std::cout << tokens << std::endl;;
    }
}