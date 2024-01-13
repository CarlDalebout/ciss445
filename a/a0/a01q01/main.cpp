#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
// #include "TokenList.h"
#include "P.h"

struct Element
{
    std::string tok;
    int type; // 0 = bool, 1 = int , 2 = octals, 3 = hex, 4 = float, 5 = doubles, 6 = string, 7 = operators
};

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

    Element pop_front();
    Element operator[](int);
    
/*==========================================================================================
Sets and Gets
==========================================================================================*/
    int size() {return tokens_.size();}
    std::vector<Element> & tokens()       { return tokens_; }
    std::vector<Element>   tokens() const { return tokens_; }

private:
    std::vector<Element> tokens_;
    std::string separators_;
};

std::ostream & operator<<(std::ostream &, TokenList);


bool found (char ch, std::string input)
{
    for(int i = 0; i < input.size(); i++)
    {
        if(ch == input[i])
            return true;
    }
    return false;
}

int isInt(std::string token)
{
    // std::cout << "checking for an int\n";
    bool checkingOctal = false;
    int start_index = 0;
    if(token[start_index] == '0')
    {
        checkingOctal = true;
    }
    bool isOctal = true;
    std::string dir = "";
    for(int i = start_index; i < token.size(); ++i)
    {
        if(!(token[i] >= 48 && token[i] <= 57))
        {
            // std::cout << "not an int found " << token[i] << " at index " << i << '\n'; 
            return i;
        }
        else if(checkingOctal && (int)token[i]-48 > 7)
            isOctal = false;
        // std::cout << dir << (int)token[i]; dir = " ";
    }
    if(checkingOctal && isOctal)
    {
        return -2;
    }
    else{
        // std::cout << "returning -1 to show that we found an int value\n";
        return -1;
    }
}

bool isFloat(std::string token, int start_index)
{
    // std::cout << "checking for a float\n";
    for(int i = start_index; i < token.size(); ++i)
    {
        if(!isdigit(token[i]) && token[i] != '.')
        {
            // std::cout << "not a float found " << token[i] << " at index " << i << '\n';
            return false;
        }
    }
    // std::cout << "returning true \n";
    return true;
}

char isOperator(char ch)
{
    switch ((int)ch)
    {
        case (int) '=':
            return '='; break;
        case (int) '+':
            return '+'; break;
        case (int) '-':
            return '-'; break;
        case (int) '*':
            return '*'; break;
        case (int) '/':
            return '/'; break;
        case (int) '%':
            return '%'; break;
        default:
            return 'n'; break;
    }
}

TokenList::TokenList(std::string input, std::string separators)
:separators_(separators)
{
    int i = 0;
    std::string token = "";
    while(input[i] != '\0')
    {
        char ch = input[i];
        if(ch == '"') //pulling a string from the user
        {   
            i++;
            ch = input[i];
            while(input[i] != '"')
            {
                ch = input[i];
                token += ch;
                i++;
            }
            // std::cout << "pushing " << token << " to tokens\n";
            tokens_.push_back({token, 6});
            token = "";
            i++;
        }
        else if(isOperator(input[i]) != 'n')
        {
            if(token != "")
            {
                int index = isInt(token);
                if(index == -1)
                {
                    std::cout << "pushing \"" << token << "\" with type int into tokens_\n";
                    Element element = {token, 1};
                    tokens_.push_back(element);
                }
                else if(index == -2)
                {
                    std::cout << "pushing \"" << token << "\" with type octal into tokens_\n";
                    Element element = {token, 2};
                    tokens_.push_back(element);
                }
                else if(isFloat(token, index))
                {
                    std::cout << "pushing \"" << token << "\" with type float into tokens_\n";
                    Element element = {token, 4};
                    tokens_.push_back(element);
                }
                else
                {
                    std::cout << "pushing \"" << token << "\" with type string into tokens_\n";
                    Element element = {token, 6};
                    tokens_.push_back(element);
                }
                token = "";
            }
            std::string temp = "";
            temp += isOperator(input[i]);
            Element element = {temp, 7};
            tokens_.push_back(element);
        }
        else if(found(ch, separators))
        {   
            if(token != "")
            {
                int index = isInt(token);
                if(index == -1)
                {
                    std::cout << "pushing \"" << token << "\" with type int into tokens_\n";
                    Element element = {token, 1};
                    tokens_.push_back(element);
                }
                else if(index == -2)
                {
                    std::cout << "pushing \"" << token << "\" with type octal into tokens_\n";
                    Element element = {token, 2};
                    tokens_.push_back(element);
                }
                else if(isFloat(token, index))
                {
                    std::cout << "pushing \"" << token << "\" with type float into tokens_\n";
                    Element element = {token, 4};
                    tokens_.push_back(element);
                }
                else
                {
                    std::cout << "pushing \"" << token << "\" with type string into tokens_\n";
                    Element element = {token, 6};
                    tokens_.push_back(element);
                }
                token = "";
            }
        }
        else
        {
            token += ch;
        }
        i++;
    }
    if(token != "")
    {
        int index = isInt(token);
        if(index == -1)
        {
            std::cout << "pushing \"" << token << "\" with type int into tokens_\n";
            Element element = {token, 1};
            tokens_.push_back(element);
        }
        else if(index == -2)
        {
            std::cout << "pushing \"" << token << "\" with type octal into tokens_\n";
            Element element = {token, 2};
            tokens_.push_back(element);
        }
        else if(isFloat(token, index))
        {
            std::cout << "pushing \"" << token << "\" with type float into tokens_\n";
            Element element = {token, 4};
            tokens_.push_back(element);
        }
        else
        {
            std::cout << "pushing \"" << token << "\" with type string into tokens_\n";
            Element element = {token, 6};
            tokens_.push_back(element);
        }
    }
    // std::cout << "returning from tokeninzing string\n";
}

void TokenList::add_separators(std::string separators)
{
    for(int i = 0; i < separators.size(); ++i)
    {
        separators_ += separators[i];
    }
}

void TokenList::push_back(std::string input)
{
    TokenList temp(input, separators_);
    for(int i = 0; i < temp.size(); ++i)
    {
        Element element = {temp.tokens_[i].tok, temp.tokens_[i].type};
        tokens_.push_back(element);
    }
    // std::cout << "tok has " << tokens_.size() << " tokens\n";
}

void TokenList::clear()
{
    tokens_.clear();
}

Element TokenList::pop_front()
{
    Element ret = tokens_[0];
    if(!tokens_.empty())
        tokens_.erase(tokens_.begin());
    return ret;
}

Element TokenList::operator[](int index)
{
    if(index >= tokens_.size())
    {
        std::cout << "!!! ERROR index out of bound !!!, Exiting\n";
        exit(0);
    }
    return tokens_[index];
}

std::ostream & operator<<(std::ostream & cout, TokenList tokens)
{
    std::string delim = "";
    // cout << tokens.size() << '\n';
    cout << '{';
    for(int i = 0; i < tokens.size(); i++)
    {
        cout << delim << tokens[i].tok; delim = " "; 
    }
    cout << '}';
    delim = "";
    cout << '\n';
    for(int i = 0; i < tokens.size(); ++i)
    {
        cout << delim << tokens[i].type; delim = " ";  
    }
    return cout;
}


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
        // p.eval_input(tokens);
        std::cout << tokens << std::endl;;
    }
}