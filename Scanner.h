#ifndef SCANNER_H
#define SCANNER_H
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

int processData(char*[], int);
int scan(std::string);
int checkIfValidCharacter(char);
int getState(char);
int isNewLine(int);
int isDigit(int);
int isLetter(int);

#endif
