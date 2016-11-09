#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <cstdlib>

//Misc constants
static const int BAD_CHARACTER = -5;
static const int GOOD_CHARACTER = 5;
static const int FILE_ERROR = -3;
static const int FSA_ERROR = -2;
static const int BEGIN_STATE = 0;

//ASCII constants
static const int NEWLINE_CHARACTER = 10;
static const int EXCLPOINT = 33;
static const int WHITESPACE_CHARACTER = 32;
static const int PERCENT = 37;
static const int AMP = 38;
static const int LPARENS = 40;
static const int RPARENS = 41;
static const int STAR = 42;
static const int PLUS = 43;
static const int COMMA = 44;
static const int MINUS = 45;
static const int PERIOD = 46;
static const int SLASH = 47;
static const int START_DIGIT = 48;
static const int END_DIGIT = 57;
static const int COLON = 58;
static const int SEMICOLON = 59;
static const int LESS = 60;
static const int EQ = 61;
static const int GREATER = 62;
static const int COMMENT_TAG = 64;
static const int START_UPPER_LETTER = 65;
static const int END_UPPER_LETTER = 90;
static const int LBRACE = 91;
static const int RBRACE = 93;
static const int START_LOWER_LETTER = 97;
static const int END_LOWER_LETTER = 122;
static const int LBRACKET = 123;
static const int RBRACKET = 125;

//FSA Table Columns
static const int NEWLINE_WHITESPACE_COL = 0;
static const int LETTER_COL = 1;
static const int DIGIT_COL = 2;
static const int EQUALS_COL = 3;
static const int EXCLPOINT_COL = 4;
static const int GREATER_COL = 5;
static const int LESS_COL = 6;
static const int COLON_COL = 7; 
static const int PLUS_COL = 8;
static const int MINUS_COL = 9;
static const int STAR_COL = 10;
static const int SLASH_COL = 11;
static const int AMP_COL = 12;
static const int PERCENT_COL = 13;
static const int PERIOD_COL = 14;
static const int LPARENS_COL = 15;
static const int RPARENS_COL = 16;
static const int COMMA_COL = 17;
static const int LBRACE_COL = 18;
static const int RBRACE_COL = 19;
static const int SEMICOLON_COL = 20;
static const int LBRACKET_COL = 21;
static const int RBRACKET_COL = 22;


//Token array sizes and data
static const int KeywordsSize = 14;
static const int RelationalOperatorsSize = 6;
static const int OtherOperatorsSize = 8;
static const int DelimitersSize = 9;
static const int TokenArraySize = 40;
static std::string Keywords[14] = {"Begin", "End", "Start", "Stop", "Iff", "Loop", "Void", "Var", "Int", "Call", "Return", "Scan", "Print", "Program"};
static std::string RelationalOperators[6] = {"=", "<", ">", "=!=", ">=>", "<=<"};
static std::string OtherOperators[8] = {"==", ":", "+", "-", "*", "/", "&", "%"};
static std::string Delimiters[9] = {".", "(", ")", ",", "{", "}", ";", "[", "]"};

static int tokenID[40] = {1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019, 1020, 1021, 1022, 1023, 1024, 1025, 1026, 1027, 1028, 1029, 1030, 1031, 1032, 1033, 1034, 1035, 1036, 1037, 1038, 1050};

static std::string tokenName[40] = {"BEGIN_tk", "END_tk", "START_tk", "STOP_tk", "IFF_tk", "LOOP_tk", "VOID_tk", "VAR_tk", "INT_tk", "CALL_tk", "RETURN_tk", "SCAN_tk", "PRINT_tk", "PROGRAM_tk", "EQUALS_tk", "LESSTHAN_tk", "GREATERTHAN_tk", "NOTEQUALTO_tk", "GREATEREQUALS_tk", "LESSEQUALS_tk", "EQUALTO_tk", "COLON_tk", "PLUS_tk", "MINUS_tk", "MULTIPLY_tk", "DIVIDE_tk", "AND_tk", "MOD_tk", "PERIOD_tk", "OPENPARENS_tk", "CLOSEPARENS_tk", "COMMA_tk", "OPENBRACES_tk", "CLOSEBRACES_tk", "SEMICOLON_tk", "OPENBRACKET_tk", "CLOSEBRACKET_tk", "ID_tk", "DIGIT_tk", "EOF_tk"};

//29x23 table of FSA States
static const int stateTable[29][23] = {
  {0, 1, 2, 3, FSA_ERROR, 7, 5, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24},
  {1037, 1, 1, 1037, 1037, 1037, 1037, 1037, 1037, 1037, 1037, 1037, 1037, 1037, 1037, 1037, 1037, 1037, 1037, 1037, 1037, 1037, 1037},
  {1038, 1038, 2, 1038, 1038, 1038, 1038, 1038, 1038, 1038, 1038, 1038, 1038, 1038, 1038, 1038, 1038, 1038, 1038, 1038, 1038, 1038, 1038},
  {1014, 1014, 1014, 28, 4, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014},
  {FSA_ERROR, FSA_ERROR, FSA_ERROR, 25, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR},
  {1015, 1015, 1015, 6, FSA_ERROR, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015},
  {FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, 27, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR},
  {1016, 1016, 1016, 8, FSA_ERROR, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016},
  {FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, 26, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR, FSA_ERROR},
  {1021, 1021, 1021, 1021, 1021, FSA_ERROR, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021},
  {1022, 1022, 1022, 1022, 1022, FSA_ERROR, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022},
  {1023, 1023, 1023, 1023, 1023, FSA_ERROR, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023},
  {1024, 1024, 1024, 1024, 1024, FSA_ERROR, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024},
  {1025, 1025, 1025, 1025, 1025, FSA_ERROR, 1025, 1025, 1025, 1025, 1025, 1025, 1025, 1025, 1025, 1025, 1025, 1025, 1025, 1025, 1025, 1025, 1025},
  {1026, 1026, 1026, 1025, 1026, FSA_ERROR, 1026, 1026, 1026, 1026, 1026, 1026, 1026, 1026, 1026, 1026, 1026, 1026, 1026, 1026, 1026, 1026, 1026},
  {1027, 1027, 1027, 1027, 1027, FSA_ERROR, 1027, 1027, 1027, 1027, 1027, 1027, 1027, 1027, 1027, 1027, 1027, 1027, 1027, 1027, 1027, 1027, 1027},
  {1028, 1028, 1028, 1028, 1028, FSA_ERROR, 1028, 1028, 1028, 1028, 1028, 1028, 1028, 1028, 1028, 1028, 1028, 1028, 1028, 1028, 1028, 1028, 1028},
  {1029, 1029, 1029, 1029, 1029, FSA_ERROR, 1029, 1029, 1029, 1029, 1029, 1029, 1029, 1029, 1029, 1029, 1029, 1029, 1029, 1029, 1029, 1029, 1029},
  {1030, 1030, 1030, 1030, 1030, FSA_ERROR, 1030, 1030, 1030, 1030, 1030, 1030, 1030, 1030, 1030, 1030, 1030, 1030, 1030, 1030, 1030, 1030, 1030},
  {1031, 1031, 1031, 1031, 1031, FSA_ERROR, 1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031},
  {1032, 1032, 1032, 1032, 1032, FSA_ERROR, 1032, 1032, 1032, 1032, 1032, 1032, 1032, 1032, 1032, 1032, 1032, 1032, 1032, 1032, 1032, 1032, 1032},
  {1033, 1033, 1033, 1033, 1033, FSA_ERROR, 1033, 1033, 1033, 1033, 1033, 1033, 1033, 1033, 1033, 1033, 1033, 1033, 1033, 1033, 1033, 1033, 1033},
  {1034, 1034, 1034, 1034, 1034, FSA_ERROR, 1034, 1034, 1034, 1034, 1034, 1034, 1034, 1034, 1034, 1034, 1034, 1034, 1034, 1034, 1034, 1034, 1034},
  {1035, 1035, 1035, 1035, 1035, FSA_ERROR, 1035, 1035, 1035, 1035, 1035, 1035, 1035, 1035, 1035, 1035, 1035, 1035, 1035, 1035, 1035, 1035, 1035},
  {1036, 1036, 1036, 1036, 1036, FSA_ERROR, 1036, 1036, 1036, 1036, 1036, 1036, 1036, 1036, 1036, 1036, 1036, 1036, 1036, 1036, 1036, 1036, 1036},
  {1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017},
  {1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018},
  {1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019},
  {1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020}
};

//Token struct
struct token {
    int tokenId;
    std::string tokenName;
    std::string matchingString;
    int lineNumber;
};

struct Node {
    std::string label;
    struct token token1;
    struct token token2;
    struct Node *child1;
    struct Node *child2;
    struct Node *child3;
    struct Node *child4;
};
#endif
