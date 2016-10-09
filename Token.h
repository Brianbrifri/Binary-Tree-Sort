#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <cstdlib>
std::string Keywords[] = {"Begin", "End", "Start", "Stop", "Iff", "Loop", "Void", "Var", "Int", "Call", "Return", "Scan", "Print", "Program"};
std::string RelationalOps[] = {"=", "<", ">", "=!=", ">=>", "<=<"};
std::string OtherOps[] = {"==", ":", "+", "-", "*", "/", "&", "%"};
std::string Delimiters[] = {".", "(", ")", ",", "{", "}", ";", "[", "]"};

typedef struct token {
    int tokenID;
    std::string tokenName;
    int lineNumber;
} token;
#endif