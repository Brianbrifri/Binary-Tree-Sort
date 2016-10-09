#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"scanner.h"

void printToken(token *tk){

	printf("%d: %s: %d\n", tk->tokenID, tk->tokenName, tk->lineNum);

}

token * setToken(int tkID, char *n, int lnum){
	token *tk;
	tk = (token *)malloc( sizeof(token) );
	tk->tokenID = tkID;
	tk->tokenName = n;
	tk->lineNum = lnum;
	return tk;
}

int checkIfKW(char *ident){
	int kw = 10;
	int i;
	i = 0;
	for(i; i<13; i++){
		if(strcmp(ident, KEYWORDS[i]) == 0){
			kw = i + 1;
			break;
		}
		else{
			kw = 15;
		}
	}
	return kw;

}
long scannerOld(FILE *fp, long fspot){
	FILE *f = fp;
	int ch;
	int numlines = 1;
	int t;
	char fstring[30];
	fseek(f, fspot, SEEK_SET);
	ch = fgetc(f);
	if(ch == '\n'){
		numlines++;
	}
	t = fscanf(f, "%s", fstring);
	printf("input length: %d\n", strlen(fstring));
	scan(fstring, numlines);
	return ftell(f);
}

long scanner(FILE *fp,  long numlines){
	int ch;
	int t;
	char *fstring[30];
        fstring[0] = '\0';
        int eof = 0;

	do {
	   ch = fgetc(fp);
	   if( ch == EOF ) {
                eof = 1;
		break;
           } else if(ch == '\n'){
		numlines++;
		break;
	   } else if ( ch == ' ' || ch == '\t' ) {
		break;
	   } else {
		size_t len = strlen( fstring );
		fstring[len] = ch;
		fstring[len+1] = '\0';
	   }
        } while (1);

	if( strlen( fstring ) > 0 ) {
		scan(fstring, numlines);
	return numlines;
}
}

void scan(char * input, int lnum){

	int isKW;
	int isDigit;
	int tkID;
	char *tkname;
	if(input[0] == '#'){
		printf("comment\n");
		return;
	}
	
	if(isdigit(input[0])){
		int i =0;
		for(i; i < strlen(input); i++){	
			if(isdigit(input[i]) == 0){
				isDigit = 0;
				printf("not a digit\n");
				printf("Error: %s not recognized.\n", input);
				return;
				break;
			}
			else{
				isDigit = 1;
			}	
		}
		if(isDigit == 1){
			//input is an int
			printf("is a digit\n");
			tkID = 1037;
			tkname = tokenName[37];		
	
		}
	}
	else if(isdigit(input[0]) == 0){
		printf("1\n");
		//check against keywords
		isKW = checkIfKW(input);
		int found;
		if(isKW != 15){
			printf("keyword\n");
			tkID = tokenID[isKW];
			tkname = tokenName[isKW];
		}
		
		else if(strlen(input) == 1){
			found = 0;
			int j = 0;
			for(j; j<9; j++){
				//checking against delimeters
	
				char *comp = DELIMETERS[j];
				if(strncmp(input, comp, 1) == 0){
					printf("delimeter found\n");
	
					tkID = (1014 + j);
					tkname = tokenName[(14 + j)];
					found = 1;
					break;
		
				}
			}		

			j = 0;
			for(j; j<6; j++){
				//checking relational
				if(strcmp(input, RELATIONAL[j]) == 0){
					//relational found
					printf("relational found\n");
					tkID = 1023 + j;
					tkname = tokenName[(23 + j)];
					found = 1;
					break;
				}
			}
		
			j = 0;
			for(j; j<7; j++){
				//checking operators
				char *c = OPERATORS[j];
				if(strcmp(input, c) == 0){
					//operator found
					printf("operator found\n");
					tkID = 1028 + j;
					tkname = tokenName[(29 +j)];
					found = 1;
					break;
				}
			}
		}
		//if strlen>2 but begins with letter its a idnetifier
		else if(strlen(input) >= 2){
			found = 0;
			if(isdigit(input[0]) == 0){
				//starts with letter
				if(strlen(input) == 2){
					int i = 0;
					for(i; i < 6; i++){
						char *r = RELATIONAL[i];
						if(strcmp(input, r) == 0){
							//relational found
							printf("relational found\n");
							tkID = 1023 + i;
							tkname = tokenName[(23 + i)];
							found = 1;
							break;
		
						}
					}

				}
			}
		}


		if(found == 0 && isdigit(input[0]) == 0){
			printf("identifier\n");
			tkID = 1000;
			tkname = "IdentTK";
		}
		
	}
	
	else{
		printf("Error: %s not recognized.\n", input);
		return;
	}
	
	token *tk;
	tk = (token *)malloc(sizeof(token));
	printf("input: %s, tkname: %s, tkID: %d, lnum: %d\n", input, tkname, tkID, lnum);

	tk = setToken(tkID, tkname, lnum);
	printf("token struct: %s linenum: %d ID: %d\n", tk->tokenName, tk->lineNum, tk->tokenID);
	printToken(tk);
	printf("\n");
}
