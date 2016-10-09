#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <cstdlib>
static std::string Keywords[] = {"Begin", "End", "Start", "Stop", "Iff", "Loop", "Void", "Var", "Int", "Call", "Return", "Scan", "Print", "Program"};
static std::string RelationalOperators[] = {"=", "<", ">", "=!=", ">=>", "<=<"};
static std::string OtherOperators[] = {"==", ":", "+", "-", "*", "/", "&", "%"};
static std::string Delimiters[] = {".", "(", ")", ",", "{", "}", ";", "[", "]"};

static int tokenID[] = {1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019, 1020, 1021, 1022, 1023, 1024, 1025, 1026, 1027, 1028, 1029, 1030, 1031, 1032, 1033, 1034, 1035, 1036, 1037, 1038, 1050};
static std::string tokenName[] = {"BEGIN_tk", "END_tk", "START_tk", "STOP_tk", "IFF_tk", "LOOP_tk", "VOID_tk", "VAR_tk", "INT_tk", "CALL_tk", "RETURN_tk", "SCAN_tk", "PRINT_tk", "PROGRAM_tk", "EQUALS_tk", "LESSTHAN_tk", "GREATERTHAN_tk", "NOTEQUALTO_tk", "GREATEREQUALS_tk", "LESSEQUALS_tk", "EQUALTO_tk", "COLON_tk", "PLUS_tk", "MINUS_tk", "MULTIPLY_tk", "DIVIDE_tk", "AND_tk", "MOD_tk", "PERIOD_tk", "OPENPARENS_tk", "CLOSEPARENS_tk", "COMMA_tk", "OPENBRACES_tk", "CLOSEBRACES_tk", "SEMICOLON_tk", "OPENBRACKET_tk", "CLOSEBRACKET_tk", "IDENT_tk", "DIGIT_tk", "EOF_tk"};

typedef struct token {
    int tokenID;
    std::string tokenName;
    int lineNumber;
} token;

#endif