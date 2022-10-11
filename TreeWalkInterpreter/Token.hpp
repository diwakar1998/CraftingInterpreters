#include"TokenType.hpp"
#include<iostream>

class Token{
public:
    TokenType type;
    std::string lexeme;
    int line;

    Token(TokenType t_type,std::string t_lexeme,int t_line):type(t_type),lexeme(t_lexeme),line(t_line){}

    std::string toString(){  return type+" "+lexeme; }
};