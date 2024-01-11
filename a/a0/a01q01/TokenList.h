#ifndef TOKENLIST_H
#define TOKENLIST_H

#include <iostream>
#include <string>
#include <vector>

class TokenList
{
public:
    TokenList()
    {}
    TokenList(std::string input, std::string separators);

/*==========================================================================================
Fucntions
==========================================================================================*/
    void add_separators(std::string);
    void push_back(std::string);
    void clear();

    std::string pop_front();
    std::string operator[](int);
    
/*==========================================================================================
Sets and Gets
==========================================================================================*/
    int size() {return tokens_.size();}
    std::vector<std::string> & tokens()       { return tokens_; }
    std::vector<std::string>   tokens() const { return tokens_; }

private:
    std::vector<std::string> tokens_;
    std::string separators_;
};

std::ostream & operator<<(std::ostream &, TokenList);

#endif