#pragma once

#include"Token.hpp"
#include<vector>
#include<unordered_map>
#include<map>
class Scanner{
    private:
        std::string source;
        std::vector<Token> tokens;
        int start = 0;
        int current = 0;
        int line = 1;
        bool isAtEnd(){ return current >= source.length();};
    public:
        Scanner(std::string source_str):source(source_str){}
        std::vector<Token> scanTokens();

}  ;