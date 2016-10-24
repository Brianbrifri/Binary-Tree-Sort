#include "Scanner.h"
#include "Token.h"
using namespace std;

string fileName, line, inputString;
char myChar;
fstream file;
string extension = ".fs16";
string preName = "out";
int currentLineNumber = 1;
int currentColumnNumber = 1;

int processData(char *argv[], int argc) {

    //If the user provides a filename, check to see if they provided an extension
    //If not, add the extension and open the file.
	if(argc > 1) {
        preName = argv[1];
        size_t found = preName.find(extension);

        if(found > preName.size()) {
          fileName = preName + extension;
        }
        else {
          fileName = preName;
          preName = fileName.substr(0, found);
        }

        file.open(fileName.c_str(), ios::in);

        if(!file) {
            perror("Error opening file");
            exit(1);
        }

        //While have not reached the end of the file
        //get each character and append it to the input string
        while(!file.eof()) {

            bool reachedEofInComment = false;
            file.get(myChar);

            //Exit immediately if a bad character is found
            if(checkIfValidCharacter(myChar) == BAD_CHARACTER) {
                cout << "at location " << currentLineNumber << ":" << currentColumnNumber << endl;
                return BAD_CHARACTER;
            }

            //If the '@' symbol is found for comments, continue on till
            //white space so as not to include the comments in the processing
            if((int) myChar == COMMENT_TAG) {
                do {
                    file.get(myChar);
                    currentColumnNumber++;

                    //if comment goes until last line, break
                    if(file.eof()) {
                        reachedEofInComment = true;
                        break;
                    }
                } while((int) myChar != WHITESPACE);
            }

            //Add all valid characters to the string
            //Do not accept the last character in the comment string
            //if comment goes until eof
            if(!reachedEofInComment) {
                inputString += myChar;
                currentColumnNumber++;
            }
        }
        file.close();
    }

    //If the user is using std input, parse the input and add it to the
    //the input string
    else {

        while(!cin.eof()) {
            bool reachedEofInComment = false;

            cin.get(myChar);

            //Exit immediately if a bad character is found
            if((checkIfValidCharacter(myChar)) == BAD_CHARACTER) {
                cout << "at location " << currentLineNumber << ":" << currentColumnNumber << endl;
                return BAD_CHARACTER;
            }

            //If the '@' symbol is found for comments, continue on till
            //white space so as not to include the comments in the processing
            if((int) myChar == COMMENT_TAG) {
                do {
                    cin.get(myChar);
                    currentColumnNumber++;

                    //if comment goes until last line, break
                    if(cin.eof()) {
                        reachedEofInComment = true;
                        break;
                    }
                } while((int) myChar != WHITESPACE);
            }

            //Add all valid characters to the string
            //Do not accept the last character in the comment string
            //if comment goes until eof
            if(!reachedEofInComment) {
                inputString += myChar;
                currentColumnNumber++;
            }
        }
    }

    //Return the results of the scan on the input string
    return scan(inputString);

}

int scan(string inputString) {
    cout << inputString << endl;
    return 0;
}

//Convert the character to ascii and check if it is in the accepted range of
//characters. If not, return the BAD_CHARACTER constant.
int checkIfValidCharacter(char myChar) {
    int asciiChar = (int) myChar;
//    cout << myChar << ": " << asciiChar << " ";

    if(asciiChar == 10) {
        currentLineNumber++;
        currentColumnNumber = 0;
    }

    if(asciiChar < 10 || (10 < asciiChar && asciiChar < 32) || (33 < asciiChar && asciiChar < 37) ||
       asciiChar == 39 || asciiChar == 63 || asciiChar == 92 || (93 < asciiChar && asciiChar < 97) ||
       asciiChar == 124 || 125 < asciiChar) {
            cout << "Found bad character " << myChar << " ";
            return BAD_CHARACTER;
    }
    else {
        return GOOD_CHARACTER;
    }
}

int getState(char myChar) {
    int asciiChar = (int) myChar;

    if(isNewLine(asciiChar)) return NEWLINE_STATE;
    else if(isDigit(asciiChar)) return DIGIT_STATE;
    else if(isLetter(asciiChar)) return LETTER_STATE;
    else return BAD_CHARACTER;
}

int isNewLine(int asciiChar) {
    return asciiChar == WHITESPACE ? WHITESPACE_STATE : 0;
}

int isDigit(int asciiChar) {
    return (START_DIGIT <= asciiChar && asciiChar <= END_DIGIT) ? DIGIT_STATE : 0;
}

int isLetter(int asciiChar) {
    return (START_UPPER_LETTER <= asciiChar && asciiChar <= END_UPPER_LETTER) ||
           (START_LOWER_LETTER <= asciiChar && asciiChar <= END_LOWER_LETTER) ? LETTER_STATE : 0;
}


