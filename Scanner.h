#ifndef SCANNER_H
#define SCANNER_H
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include "Token.h"

int processData(char*[], int);
int scan(std::string);
int checkIfValidCharacter(char);
std::string getTokenName(int);
int matchIdToKeyword(std::string);
void printToken(token);
int getCharacterColumn(char);
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
