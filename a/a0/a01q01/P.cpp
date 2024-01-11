#include "P.h"

void P::eval_token(std::string tokens)
{
    // try
    // {
    //     int index = isint(tokens[0]);
    //     if(index != -1)
    //     {
    //         if(isflout(tokens[0], index))
    //         {
    //             throw std::invalid_argument("\"" + tokens[0] +"\" is not a int i dont know how to handle floats or double yet");
    //         }
    //         else if(tokens.size() != 1)
    //         {
    //             if(tokens[1] == "=")
    //             {
    //                 index = isint(tokens[2]);
    //                 if(index != -1)
    //                 {
    //                     if(isflout(tokens[2], index))
    //                     {
    //                         throw std::invalid_argument("\"" + tokens[2] + "\" is not a int i dont know how to handle floats or double yet");
    //                     }
    //                 }
    //                 else
    //                 {
    //                     // std::cout << "inserting key: " << tokens[0] 
    //                     //         << " with value: " << std::stoi(tokens[2]) 
    //                     //         << " into the symtable\n";
    //                     symtable_.insert({tokens[0], std::stoi(tokens[2])});
    //                 }
    //             }
    //             else
    //             {}
    //         }
    //         else
    //         {
    //             std::map<std::string, int>::iterator it_symtable;
    //             it_symtable = symtable_.find(tokens[0]);
    //             if(it_symtable != symtable_.end())
    //                 std::cout << it_symtable->second << '\n';
    //             else
    //                 throw std::invalid_argument("\"" + tokens[0] +"\" is neither a value or found in the symtable");
    //         }
    //     }
    //     else
    //     {
    //         // if()
    //         std::cout << std::stoi(tokens[0]) << '\n';
    //     }
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << "!!! Error: " << e.what() << std::endl;
    // }
}

void P::eval_input(Token toklens)
{

}
