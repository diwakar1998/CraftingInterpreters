#include<iostream>
#include<vector>
#include<fstream>
#include"Scanner.hpp"


class Lox{
    
    public:
    static bool hadError;
    Lox(){
        hadError= false;
    }
    
    void runFile(std::string filePath){
        std::fstream inFile;
        inFile.open(filePath,std::ios::in);
        std::string buffer;
        // for(;;){
            getline(inFile,buffer);
            // cout<<buffer;
            run(buffer);
            if(hadError) exit(65);
        // }
    }

    void runPrompt(){
        for(;;){
            std::cout<<"> ";
            std::string line;
            getline(std::cin,line);
            if(line.length()==0)break;
            run(line);
            hadError = false;
        }
    }
    /***
     * 
     * continue at 4.2
     * 
     * 
     * 
    */
    void run(std::string source){
        Scanner scanner(source);
       std::vector<Token> tokens = scanner.scanTokens();

        for(Token token:tokens){
            std::cout<<token;
        }
    }
    void error(int line,std::string message){
        report(line,"",message);
    }

    void report(int line, std::string where,std::string message){
        std::cout<<"[line "<<line<<" ] Error"<<where<<": "<<message;
        hadError = true;
    }
};

int main(int argc, char const *argv[])
{
    Lox lox;
    if(argc>2){
        std::cout<<"Usage: jlox [script]\n";
        exit(0);
    }
    else if(argc == 2){
        lox.runFile(argv[1]);
    }
    else{
        lox.runPrompt();
    }

    return 0;
}
