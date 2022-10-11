#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Lox{
    public:
    static bool hadError;
    Lox(){
        hadError= false;
    }
    
    void runFile(string filePath){
        fstream inFile;
        inFile.open(filePath,ios::in);
        string buffer;
        // for(;;){
            getline(inFile,buffer);
            // cout<<buffer;
            run(buffer);
            if(hadError) exit(65);
        // }
    }

    void runPrompt(){
        for(;;){
            cout<<"> ";
            string line;
            getline(cin,line);
            if(line.length()==0)break;
            run(line);
            hadError = false;
        }
    }

    void run(string source){
        Scanner scanner = new Scanner(source);
        vector<Token> tokens = scanner.scanTokens();

        for(Token token:tokens){
            cout<<token;
        }
    }
    void error(int line,string message){
        report(line,"",message);
    }

    void report(int line, string where,string message){
        cout<<"[line "<<line<<" ] Error"<<where<<": "<<message;
        hadError = true;
    }
};

int main(int argc, char const *argv[])
{
    Lox lox;
    if(argc>2){
        cout<<"Usage: jlox [script]\n";
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
