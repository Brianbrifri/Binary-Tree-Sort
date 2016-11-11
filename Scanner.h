#ifndef SCANNER_H
#define SCANNER_H
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include "Token.h"
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
void program(Node*, struct token*);
Node *block(struct token*);
Node *vars(struct token*);
Node *mvars(struct token*);
Node *expr(struct token*);
Node *M(struct token*);
Node *T(struct token*);
Node *F(struct token*);
Node *R(struct token*);
Node *stats(struct token*);
Node *mstats(struct token*);
Node *stat(struct token*);
Node *in(struct token*);
Node *out(struct token*);
Node *ifs(struct token*);
Node *loop(struct token*);
Node *assign(struct token*);
Node *RO(struct token*);

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
