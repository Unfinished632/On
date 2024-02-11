#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <memory>
#include <vector>
#include "../include/syntax.h"

//std::vector<Statement> Parse(std::list<std::string> tokens);

std::list<struct Token> Lexer(std::string code)
{
    std::list<struct Token> tokens[1];
    std::string arg = "";

    //Lexing
    bool allowSpaces = false;
    struct Token token;
    int line = 1;
    
    for (int i = 0; i < code.length(); i++)
    {
        token.collumn = i + 1;
        token.line = line;

        arg += code[i];

        if (arg.back() == '\n')
            arg.pop_back();

        if (arg.back() == ' ' && !allowSpaces)
        {
            arg.pop_back();
            token.value = arg;

            if (arg != "")
                tokens->push_back(token);
            arg = "";
        }
        else if (arg.back() == '"')
        {
            allowSpaces = !allowSpaces;

            if (allowSpaces)
            {
                token.value = "\"";
                tokens->push_back(token);
            }
            else
            {
                arg.pop_back();

                token.value = arg;
                token.collumn = (i - arg.length()) + 1;
                tokens->push_back(token);

                token.value = "\"";
                token.collumn = i + 1;
                tokens->push_back(token);
            }
            
            arg = "";
        }
        
        else if (i + 1 < code.length())
        {
            switch (arg.back())
            {
                case ';':
                    arg.pop_back();

                    if (arg != "")
                    {
                        token.value = arg;
                        token.collumn = (i - arg.length()) + 1;
                        tokens->push_back(token);
                    }

                    token.value = ";";
                    token.collumn = i + 1;
                    tokens->push_back(token);
                    break;
                case ':':
                    arg.pop_back();
                    
                    if (arg != "")
                    {
                        token.value = arg;
                        token.collumn = (i - arg.length()) + 1;
                        tokens->push_back(token);
                    }

                    token.value = ":";
                    token.collumn = i + 1;
                    tokens->push_back(token);
                    break;
                case ',':
                    arg.pop_back();
                    
                    if (arg != "")
                    {
                        token.value = arg;
                        token.collumn = (i - arg.length()) + 1;
                        tokens->push_back(token);
                    }

                    token.value = ",";
                    token.collumn = i + 1;
                    tokens->push_back(token);
                    break;
            }

            arg = "";
        }
        else if (i + 1 >= code.length())
        {
            token.value = arg;
            token.collumn = (i - arg.length()) + 1;

            tokens->push_back(token);
            arg = "";
        }
    }

    return *tokens;
}

/*
std::vector<Statement> Parse(std::list<std::string> tokens)
{
    std::vector<Statement> ast;

    for (std::string i : tokens)
    {
        Statement statement;
        
    }
}
*/