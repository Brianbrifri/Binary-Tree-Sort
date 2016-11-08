#ifndef SCANNER_H
#define SCANNER_H
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include "Token.h"

//Main functions of Scanner
int processData(char*[], int);
int scan(std::string);

//Token functions
void scanner(struct token*);
std::string getTokenName(int);
void printToken(token*);

//Node functions

//Parsing functions
int checkIfValidCharacter(char);
int matchIdToKeyword(std::string);
int getCharacterColumn(char);
std::string cleanTokenString(std::string);
bool stateIsIdent(int);
int isNewLine(int);
int isWhiteSpace(int);
int isDigit(int);
int isLetter(int);
int isEqSign(int);
int isLessThan(int);
int isGreaterThan(int);
int isExclPoint(int);
int isColon(int);
int isPlus(int);
int isMinus(int);
int isStar(int);
int isSlash(int);
int isAmper(int);
int isPercent(int);
int isPeriod(int);
int isLParens(int);
int isRParens(int);
int isComma(int);
int isLBrace(int);
int isRBrace(int);
int isSemiColon(int);
int isLBracket(int);
int isRBracket(int);
int isCommentTag(int);

#endif
