#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <map>
// #include "TokenList.h"
// #include "P.h"

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
        case (int) '(':
            return '('; break;
        case (int) ')':
            return ')'; break;
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
                    // std::cout << "pushing \"" << token << "\" with type int into tokens_\n";
                    Element element = {token, 1};
                    tokens_.push_back(element);
                }
                else if(index == -2)
                {
                    // std::cout << "pushing \"" << token << "\" with type octal into tokens_\n";
                    Element element = {token, 2};
                    tokens_.push_back(element);
                }
                else if(isFloat(token, index))
                {
                    // std::cout << "pushing \"" << token << "\" with type float into tokens_\n";
                    Element element = {token, 4};
                    tokens_.push_back(element);
                }
                else
                {
                    // std::cout << "pushing \"" << token << "\" with type string into tokens_\n";
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
                    // std::cout << "pushing \"" << token << "\" with type int into tokens_\n";
                    Element element = {token, 1};
                    tokens_.push_back(element);
                }
                else if(index == -2)
                {
                    // std::cout << "pushing \"" << token << "\" with type octal into tokens_\n";
                    Element element = {token, 2};
                    tokens_.push_back(element);
                }
                else if(isFloat(token, index))
                {
                    // std::cout << "pushing \"" << token << "\" with type float into tokens_\n";
                    Element element = {token, 4};
                    tokens_.push_back(element);
                }
                else
                {
                    // std::cout << "pushing \"" << token << "\" with type string into tokens_\n";
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
            // std::cout << "pushing \"" << token << "\" with type int into tokens_\n";
            Element element = {token, 1};
            tokens_.push_back(element);
        }
        else if(index == -2)
        {
            // std::cout << "pushing \"" << token << "\" with type octal into tokens_\n";
            Element element = {token, 2};
            tokens_.push_back(element);
        }
        else if(isFloat(token, index))
        {
            // std::cout << "pushing \"" << token << "\" with type float into tokens_\n";
            Element element = {token, 4};
            tokens_.push_back(element);
        }
        else
        {
            // std::cout << "pushing \"" << token << "\" with type string into tokens_\n";
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

class P
{
public:
/*==========================================================================================
    Constructors
==========================================================================================*/
    P()
    {}

/*==========================================================================================
    Functions
==========================================================================================*/
    void  eval_token_list(std::vector<Element> tokens);
    void  eval_token(Element token);
    int   get_righthand(std::vector<Element> tokens, int start);

private:
/*==========================================================================================
    Maps
==========================================================================================*/
    std::map<std::string, int> symtable_;

};

std::string get_lefthand(std::vector<Element> tokens, int end)
{
    if(end > 1)
    {
        std::string val = "";
        std::string dir = "";
        for(int i = 0; i < end; ++i)
        {
            val += (dir + tokens[i].tok); dir = " ";
        }
        std::cout << "ERROR: \"" << val << "\" is not a variable name\n";
        val = "ERROR BAD NAME";
        return val;
    }
    else if(end == 1 && tokens[0].type != 6 || isdigit(tokens[0].tok[0]) )
    {
        std::cout << "ERROR: \"" << tokens[0].tok << "\" is not a variable name\n";
        return "ERROR BAD NAME";
    }
    else
    {
        return tokens[0].tok;
    }
}

int P::get_righthand(std::vector<Element> tokens, int start)
{
    // 3 * 4 + 6 = 34*6+
    // x = 3
    // x * 4 + 6 = 34*6+
    std::vector<std::string> operator_stack;
    std::vector<std::string> Postfix_string;
    
    for(int i = start; i < tokens.size(); ++i)
    {
        if(tokens[i].type == 6)
        {
            std::map<std::string, int>::iterator it_symtable;
            it_symtable = symtable_.find(tokens[i].tok);
            if(it_symtable != symtable_.end())
            {
                std::string temp = std::to_string(it_symtable->second);
                Postfix_string.push_back(temp);
            }
            else
            {
                std::cout << "ERROR: \"" << tokens[i].tok << "\" is not a value nor found in the symtable\n";
                // value error = -2147483648
                return -2147483648;
            }
        }
        else if(tokens[i].type == 7 && tokens[i].tok != "=")
        {
            switch ((int)tokens[i].tok[0])
            {
                case (int)'+':
                    {
                        // std::cout << "in 'x' case\n";
                        if(i+1 == tokens.size())
                        {
                            std::cout << "ERROR: right operand for \"+\" is missing\n";
                            return -2147483647;
                        }
                        while(!operator_stack.empty() && (operator_stack.back() == "*" || operator_stack.back() == "/"))
                        {
                            // std::cout << "pusing to Postfix_string\n";
                            Postfix_string.push_back(operator_stack.back());
                            operator_stack.pop_back();
                        }
                        operator_stack.push_back("+");
                    }
                    break;
                case (int)'-':
                    {
                        if(i+1 == tokens.size())
                        {
                            std::cout << "ERROR: right operand for \"-\" is missing\n";
                            return -2147483647;
                        }
                        while(!operator_stack.empty() && (operator_stack.back() == "*" || operator_stack.back() == "/"))
                        {
                            Postfix_string.push_back(operator_stack.back());
                            operator_stack.pop_back();
                        }
                        operator_stack.push_back("-");
                    }
                    break;
                case (int)'*':
                    {
                        if(i+1 == tokens.size())
                        {
                            std::cout << "ERROR: right operand for \"*\" is missing\n";
                            return -2147483647;
                        }
                        operator_stack.push_back("*");
                    }
                    break;
                case (int)'/':
                    {
                        if(i+1 == tokens.size())
                        {
                            std::cout << "ERROR: right operand for \"/\" is missing\n";
                            return -2147483647;
                        }
                        operator_stack.push_back("/");
                    }
                    break;
                case (int)'(':
                    {
                        if(i+1 == tokens.size())
                        {
                            std::cout << "ERROR: missing right bracket INCORRECT MATHMATICAL FORMATE \n";
                            return -2147483647;
                        }
                        operator_stack.push_back("(");
                    }
                    break;
                case (int)')':
                    {
                        while(operator_stack.back() != "(")
                        {
                            if(operator_stack.empty())
                            {
                                std::cout << "ERROR: missing left bracket invalid left side INCORRECT MATHMATICAL FORMAT\n";
                                return -2147483647;
                            }
                            Postfix_string.push_back(operator_stack.back());
                            operator_stack.pop_back();
                        }
                        operator_stack.pop_back();
                    }
                    break;
                default:
                    break;
            }
        }
        else if(tokens[i].type == 1)
        {
            Postfix_string.push_back(tokens[i].tok);
        }
        else
        {
            std::cout << "ERROR: invalid value type INCORRECT MATHMATICAL FORMAT\n";
            return -2147483647;
        }

        // //debugging code
        // std::cout << tokens[i].tok << "\toperator_stack: ";
        // std::string dir = "";
        // for(int j = 0; j < operator_stack.size(); ++j)
        // {
        //     std::cout << dir << operator_stack[j]; dir = " "; 
        // }
        // std::cout << "\tPostfix_string: ";
        // dir = "";
        // for(int j = 0; j < Postfix_string.size(); ++j)
        // {
        //     std::cout << dir << Postfix_string[j]; dir = " ";
        // }
        // std::cout << '\n';
        // //
    }

    while(!operator_stack.empty())
    {
        Postfix_string.push_back(operator_stack.back());
        operator_stack.pop_back();
    }

    // std::string dir = "";
    // for(int i = 0; i < Postfix_string.size(); ++i)
    // {
    //     std::cout << dir << Postfix_string[i]; dir = " ";
    // }
    // std::cout << '\n';

    std::vector<int> Reverse_Polish_Stack;
    for(int i = 0; i < Postfix_string.size(); ++i)
    {
        switch ((char)Postfix_string[i][0])
        {
            case (int)'+':
            {
                if(Reverse_Polish_Stack.size() == 1)
                {
                
                }
                else
                {
                    Reverse_Polish_Stack[Reverse_Polish_Stack.size()-2] = Reverse_Polish_Stack[Reverse_Polish_Stack.size()-2] + Reverse_Polish_Stack.back();
                    Reverse_Polish_Stack.pop_back();
                }
            }
                break;
            case (int)'-':
            {
                if(Reverse_Polish_Stack.size() == 1)
                {
                    Reverse_Polish_Stack.back() = -Reverse_Polish_Stack.back();
                }
                else
                {
                    Reverse_Polish_Stack[Reverse_Polish_Stack.size()-2] = Reverse_Polish_Stack[Reverse_Polish_Stack.size()-2] - Reverse_Polish_Stack.back();
                    Reverse_Polish_Stack.pop_back();
                }
            }
                break;
            case (int)'*':
            {
                if(Reverse_Polish_Stack.size() == 1)
                {
                    std::cout << "Error: not left element to multiply INCORRECT MATHMATICAL FORMAT\n";
                    return -2147483647;
                }
                else
                {
                    Reverse_Polish_Stack[Reverse_Polish_Stack.size()-2] = Reverse_Polish_Stack[Reverse_Polish_Stack.size()-2] * Reverse_Polish_Stack.back();
                    Reverse_Polish_Stack.pop_back();
                }
            }
            break;
            case (int)'/':
            {
                if(Reverse_Polish_Stack.size() == 1)
                {
                    std::cout << "Error: not left element to devide INCORRECT MATHMATICAL FORMAT\n";
                    return -2147483647;
                }
                else
                {
                    Reverse_Polish_Stack[Reverse_Polish_Stack.size()-2] = Reverse_Polish_Stack[Reverse_Polish_Stack.size()-2] / Reverse_Polish_Stack.back();
                    Reverse_Polish_Stack.pop_back();
                }
            }
                break;
            default:
                Reverse_Polish_Stack.push_back(std::stoi(Postfix_string[i]));
                break;
        }

        // std::cout << Postfix_string[i] << "\t Reverse_Polish_Stack: ";
        // std::string dir = "";
        // for(int j = 0; j < Reverse_Polish_Stack.size(); ++j)
        // {
        //     std::cout << dir << Reverse_Polish_Stack[j]; dir = " ";
        // }
        // std::cout << '\n';
    }

    // //printing Reverse_Polish_Stack
    // dir = "";
    // for(int i = 0; i < Reverse_Polish_Stack.size(); ++i)
    // {
    //     std::cout << dir << Reverse_Polish_Stack[i]; dir = " ";
    // }
    // std::cout << '\n';
    // //

    if(!Reverse_Polish_Stack.empty())
    {
        return Reverse_Polish_Stack.back();
    }
    else
    {
        //returning no value found error
        std::cout << "ERROR: No Righthand value provided\n";
        return 2147483647;
    }
}


void P::eval_token_list(std::vector<Element> tokens)
{
    // std::cout << tokens.size() << '\n';
    int end = tokens.size();
    for(int i = 0; i < end; ++i)
    {
        if(tokens[i].type == 7)
        {
            switch ((int)tokens[i].tok[0])
            {
                case (int)'=':
                {   
                    if(tokens.size() > 2 && i > 0)
                    {
                        //gathering left and right sides of the operator
                        std::string variable_name = get_lefthand(tokens, i);
                        int value = get_righthand(tokens, i+1);
                        
                        //checking for errors
                        if(variable_name == "ERROR BAD NAME" || value == -2147483648 || value == -2147483647 || value == 2147483647)
                            return;
                        
                        //assingning value to the symtable
                        std::map<std::string, int>::iterator it_symtable;
                        it_symtable = symtable_.find(variable_name);
                        if(it_symtable != symtable_.end())
                        {
                            // std::cout << "writing over existing value\n";
                            it_symtable->second = value;
                        }
                        else
                        {
                            // std::cout << "pushing new value into the symtable\n";
                            symtable_.insert({tokens[i-1].tok, value});
                        }
                        return;
                    }
                    else
                    {
                        std::cout << "Invalid Command for \"=\"\n";
                        return;
                    }
                } 
                    break;
                default:
                    break;
            }
        }
        else
        {
            switch (tokens[i].type)
            {
                case 0:
                    if(tokens[i].tok == "True" || tokens[i].tok == "true" || tokens[i].tok == "1")
                        std::cout << "true\n";
                    else if(tokens[i].tok == "False" || tokens[i].tok == "false" || tokens[i].tok == "0")
                        std::cout << "false\n";
                    break;
                case 1:
                    {
                        int value = get_righthand(tokens, 0);
                        if(value == -2147483648 || value == -2147483647 || value == 2147483647)
                            return;
                        std::cout << value << '\n';
                        return;
                    }   break;
                case 2:
                    std::cout << "ERROR: I dont know how to understand Octals yet\n";
                    break;
                case 3:
                    std::cout << "ERROR: I dont know how to understand Hex yet\n";
                    break;
                case 4:
                    std::cout << "ERROR: I dont know how to understand floats yet\n";
                    break;
                case 5:
                    std::cout << "ERROR: I dont know how to understand doubles yet\n";
                    break;
                case 6:
                    {
                        if(i+1 == end)
                        {
                            std::map<std::string, int>::iterator it_symtable;
                            it_symtable = symtable_.find(tokens[i].tok);
                            if(it_symtable != symtable_.end())
                            {
                                std::cout << it_symtable->second << '\n';
                            }
                            else
                            {
                                std::cout << "ERROR: \"" << tokens[i].tok << "\" is neither a value nor found in the symtable\n";
                            }
                        }
                    }
                    break;
                case 7:
                    break;
                default:
                    break;
            }
        }
    }
}

void P::eval_token(Element token)
{
    
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
        // std::cout << tokens << std::endl;;
        p.eval_token_list(tokens.tokens());
    }
}