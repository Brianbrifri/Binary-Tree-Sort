#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include"scanner.h"

int main (int argc, char *argv[]){
	
	int args = argc;

	if(args == 1){
		//reading from keyboard
		printf("taking input from keyboard\n");
		printf("Enter 'EOF' to quit.\n");
		char in[81];
		char *comp = "EOF";
		int ln = 0;
		do{
			printf("Enter a string: ");
			gets(in);
			if(strcmp(in, "EOF") == 0){
				int IDtk = 1050;
				char *nametk = "EOFTK";
				token *tokentk;
				tokentk = setToken(IDtk, nametk, ln);
				printToken(tokentk);
			}
			else{
				token *intk;
				scan(in, ln);
				ln++;
			}


		}while(strcmp(in, "EOF") != 0);
	}

	if(args == 2){
		//reading from file
		//file ptr to open and read from file
		printf("reading from file provided\n");
		char *file = (char *)malloc(sizeof(argv[1]) + 7);
		file = argv[1];
		strcat(file, ".4280");
		

		FILE *fileptr;
	
		if( (fileptr = fopen(file, "r")) == NULL ) {
			printf("Cannot open input file. \n");
			perror("File open error.\n");
			exit(0);
		}


		int ch;
		int numlines = 1;
		int t;
		char fstring [80];
		do{
			printf("line num = %d\n", numlines);
			numlines = scanner(fileptr, fstring, numlines);
		}while( strlen( fstring ) > 0 );
			
		int tkID = 1050;
		char *tkname = "EOFTK";
		token *eoftk;
		eoftk = setToken(tkID, tkname, numlines);
		printToken(eoftk);

		//close file
		fclose(fileptr);
	}


	

	return 0;
}
