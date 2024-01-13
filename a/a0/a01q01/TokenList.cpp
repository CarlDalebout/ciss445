#include <iostream>
#include <string>
#include "TokenList.h"

// bool found (char ch, std::string input)
// {
//     for(int i = 0; i < input.size(); i++)
//     {
//         if(ch == input[i])
//             return true;
//     }
//     return false;
// }

// int isInt(std::string token)
// {
//     // std::cout << "checking for an int\n";
//     bool checkingOctal = false;
//     int start_index = 0;
//     if(token[0] == '+' || token[0] == '-')
//     {
//         start_index = 1;
//     }
//     if(token[start_index] == '0')
//     {
//         checkingOctal = true;
//     }
//     bool isOctal = true;
//     std::string dir = "";
//     for(int i = start_index; i < token.size(); ++i)
//     {
//         if(!isdigit(token[i]))
//         {
//             // std::cout << "not an int found " << token[i] << " at index " << i << '\n'; 
//             return i;
//         }
//         else if(checkingOctal && (int)token[i]-48 > 7)
//             isOctal = false;
//         // std::cout << dir << (int)token[i]; dir = " ";
//     }
//     if(checkingOctal && isOctal)
//     {
//         return -2;
//     }
//     else{
//         // std::cout << "returning -1 to show that we found an int value\n";
//         return -1;
//     }
// }

// bool isFloat(std::string token, int start_index)
// {
//     // std::cout << "checking for a float\n";
//     for(int i = start_index; i < token.size(); ++i)
//     {
//         if(!isdigit(token[i]) && token[i] != '.')
//         {
//             // std::cout << "not a float found " << token[i] << " at index " << i << '\n';
//             return false;
//         }
//     }
//     // std::cout << "returning true \n";
//     return true;
// }

// bool isOperator(std::string token)
// {
//     std::string operators = {"=+-*/%"};
//     for(int i = 0; i <operators.size(); ++i)
//     {
//         if(token[i] == operators[i])
//             return true;
//     }
//     return false;
// }

// TokenList::Tokens(std::string input, std::string separators)
// :separators_(separators)
// {
//     int i = 0;
//     std::string token = "";
//     while(input[i] != '\0')
//     {
//         char ch = input[i];
//         if(ch == '"') //pulling a string from the user
//         {   
//             i++;
//             ch = input[i];
//             while(input[i] != '"')
//             {
//                 ch = input[i];
//                 token += ch;
//                 i++;
//             }
//             // std::cout << "pushing " << token << " to tokens\n";
//             tokens_.push_back({token, 6});
//             token = "";
//             i++;
//         }
//         else if(found(ch, separators))
//         {   
//             if(token != "")
//             {
//                 int index = isInt(token);
//                 if(index == -1)
//                 {
//                     std::cout << "pushing \"" << token << "\" with type int into tokens_\n";
//                     tokens_.push_back({token, 1});
//                 }
//                 else if(index == -2)
//                 {
//                     std::cout << "pushing \"" << token << "\" with type octal into tokens_\n";
//                     tokens_.push_back({token, 2});
//                 }
//                 else if(isFloat(token, index))
//                 {
//                     std::cout << "pushing \"" << token << "\" with type float into tokens_\n";
//                     tokens_.push_back({token, 4});
//                 }
//                 else if(isOperator(token))
//                 {
//                     std::cout << "pushing \"" << token << "\" with type operator into tokens_\n";
//                     tokens_.push_back({token, 7});
//                 }
//                 else
//                 {
//                     std::cout << "pushing \"" << token << "\" with type string into tokens_\n";
//                     tokens_.push_back(token);
//                 }
//                 token = "";
//             }
//         }
//         else
//         {
//             token += ch;
//         }
//         i++;
//     }
//     if (token != "")
//     {
//         int index = isInt(token);
//         if(index == -1)
//         {
//             std::cout << "pushing \"" << token << "\" with type int into tokens_\n";
//             tokens_.push_back({token, 1});
//         }
//         else if(index == -2)
//         {
//             std::cout << "pushing \"" << token << "\" with type octal into tokens_\n";
//             tokens_.push_back({token, 2});
//         }
//         else if(isFloat(token, index))
//         {
//             std::cout << "pushing \"" << token << "\" with type float into tokens_\n";
//             tokens_.push_back({token, 4});
//         }
//         else if(isOperator(token))
//         {
//             std::cout << "pushing \"" << token << "\" with type operator into tokens_\n";
//             tokens_.push_back({token, 7});
//         }
//         else
//         {
//             std::cout << "pushing \"" << token << "\" with type string into tokens_\n";
//             tokens_.push_back({token, 6});
//         }
//     }
//     // std::cout << "returning from tokeninzing string\n";
// }

// void TokenList::add_separators(std::string separators)
// {
//     for(int i = 0; i < separators.size(); ++i)
//     {
//         separators_ += separators[i];
//     }
// }

// void TokenList::push_back(std::string input)
// {
//     Tokens temp(input, separators_);
//     for(int i = 0; i < temp.size(); ++i)
//     {
//         tokens_.push_back(temp[i]);
//     }
//     // std::cout << "tok has " << tokens_.size() << " tokens\n";
// }

// void TokenList::clear()
// {
//     tokens_.clear();
// }

// std::string TokenList::pop_front()
// {
//     std::string ret = tokens_[0];
//     if(!tokens_.empty())
//         tokens_.erase(tokens_.begin());
//     return ret;
// }

// std::string TokenList::operator[](int index)
// {
//     if(index >= tokens_.size())
//     {
//         std::cout << "!!! ERROR index out of bound !!!, Exiting\n";
//         exit(0);
//     }
//     return tokens_[index];
// }

// std::ostream & operator<<(std::ostream & cout, TOKENLIST tokens)
// {
//     std::string delim = "";
//     // cout << tokens.size() << '\n';
//     cout << '{';
//     for(int i = 0; i < tokens.size(); i++)
//     {
//         cout << delim << tokens[i]; delim = " "; 
//     }
//     cout << '}';
//     delim = "";
//     cout << '\n';
//     for(int i = 0; i < tokens.size(); ++i)
//     {
//         cout << delim << tokens.tokens_[i].type; delim = " ";  
//     }
//     return cout;
// }