#ifndef SCANNER_H
#define SCANNER_H
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include "Token.h"
#include "Stack.h"
#include "treePrint.h"

//Main functions of Scanner
int processData(char*[], int);
int scan(std::string);

//Token functions
void scanner(struct token*);
std::string getTokenName(int);
struct token returnInstance(struct token*);
void printToken(token*);

//Node functions
void initNode(Node*, std::string);
Node *program(struct token*, Stack*);
Node *block(struct token*, Stack*);
Node *vars(struct token*, Stack*);
Node *mvars(struct token*, Stack*);
Node *expr(struct token*, Stack*);
Node *M(struct token*, Stack*);
Node *T(struct token*, Stack*);
Node *F(struct token*, Stack*);
Node *R(struct token*, Stack*);
Node *stats(struct token*, Stack*);
Node *mstats(struct token*, Stack*);
Node *stat(struct token*, Stack*);
Node *in(struct token*, Stack*);
Node *out(struct token*, Stack*);
Node *ifs(struct token*, Stack*);
Node *loop(struct token*, Stack*);
Node *assign(struct token*, Stack*);
Node *RO(struct token*, Stack*);

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
