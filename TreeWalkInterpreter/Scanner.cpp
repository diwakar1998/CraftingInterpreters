#include"Scanner.hpp"


std::vector<Token> Scanner::scanTokens(){
    while(!isAtEnd()){
        start = current;
        scanToken();
    }
    Token temp(EOF_,"",line);
    tokens.push_back(temp);
    return tokens;
}