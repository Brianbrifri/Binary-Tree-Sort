#ifndef TOKEN_H
#define TOKEN_H

/*alphabet: all letters, digit plus extra char and WS
identifiers: begin with letter and continue with any
	number of letters and digits
keywords: reserved
	START, FINISH, THEN, IF, WHILE, INT, DO, FREAD, FPRINT, VOID
	RETURN, PROGRAM, DUMMY
relational operaters: == < > != >> <<
other operators: = : + - * / %
delimiters: . ( ) , { } ; [ ]
integers: any sequense of digits
 	no sign
	assume no longer than  8 digits
comments: start with # end with a space will be ignored
*/


 static char *KEYWORDS[13] = {"START", "FINISH", "THEN", "IF", "WHILE", "INT", "DO", "FREAD", "FPRINT", "VOID", "RETURN", "PROGRAM", "DUMMY"};
static char *DELIMETERS[9] = { ".", "(", ")", ",", "{", "}", ";", "[", "]"};
static char *RELATIONAL[6] ={ "==", "<", ">", "!=", ">>", "<<"};
static char *OPERATORS[7] = {"=", ":", "+", "-", "*", "/", "%"};

//token IDs
static int tokenID[] = {1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019, 1020, 1021, 1022, 1023, 1024, 1025, 1026, 1027, 1028, 1029, 1030, 1031, 1032, 1033, 1034, 1035, 1036, 1037};

static char *tokenName[] = {"IdentTk", "StartTk", "FinishTk", "ThenTk", "IfTk", "WhileTk", "IntTk","DoTk", "FreadTk", "FprintTk", "VoidTk", "ReturnTk", "ProgramTk", "DummyTk", "periodTk", "openParenTk", "closeParenTk", "commaTk", "openBracesTk", "closeBracesTk", "semicolTk", "openBrcktTk", "closeBrcktTk", "equalToTk", "lessThanTk", "greaterThanTk", "notEqualTk", "greaterEqualTk", "lessEqualTk", "equalsTk", "colonTk", "plusTk", "minusTk", "multTk", "divTk", "modTk", "KeyWordTk", "digitTk"};

typedef struct token{

	int tokenID;
	char *tokenName;
	int lineNum;
}token; 



#endif
