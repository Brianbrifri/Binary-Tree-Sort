#ifndef SCANNER_H
#define SCANNER_H

#include"token.h"


void printToken(token *tk);
token * setToken(int tkID, char *n, int lnum);
int checkIfKW(char *);
void scan(char [], int);
void getID(char []);
long scanner(FILE *fp, char  *,  long);
#endif
