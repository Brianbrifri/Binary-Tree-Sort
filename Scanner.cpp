#include "Scanner.h"
using namespace std;

string fileName, line, inputString;
char myChar;
fstream file;
string extension = ".fs16";
string preName = "out";
int currentLineNumber = 1;
int currentColumnNumber = 1;
int locationInString = 0;

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
            return FILE_ERROR;
        }

        //While have not reached the end of the file
        //get each character and append it to the input string
        while(!file.eof()) {
            

            bool reachedEofInComment = false;
            file.get(myChar);

            if(myChar == '\n') {
                currentLineNumber++;
                currentColumnNumber = 0;
            }

            //Exit immediately if a bad character is found
            if(getCharacterColumn(myChar) == BAD_CHARACTER) {
                cout << "Found bad character at location " << currentLineNumber << ":" << currentColumnNumber << endl;
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
                } while((int) myChar != WHITESPACE_CHARACTER);
            }

            //cout << myChar;
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

            if(myChar == '\n') {
                currentLineNumber++;
                currentColumnNumber = 0;
            }

            //Exit immediately if a bad character is found
            if((getCharacterColumn(myChar)) == BAD_CHARACTER) {
                cout << "Found bad character at location " << currentLineNumber << ":" << currentColumnNumber << endl;
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
                } while((int) myChar != WHITESPACE_CHARACTER || (int) myChar != NEWLINE_CHARACTER);
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
  struct token *myToken;

  myToken = scanner();
  cout << myToken->tokenId << endl;
  delete myToken;
  myToken = NULL;
  myToken = scanner();
  cout << myToken->tokenId << endl;

  return 0;
}

struct token * scanner() {
  int state = BEGIN_STATE;
  bool lastStateNotFinal = true;
  string currentTokenString = "";
  
  while(locationInString < inputString.size()) {
     state = stateTable[state][getCharacterColumn(inputString[locationInString])]; 
      if(state >= 1000) {
          currentTokenString = cleanTokenString(currentTokenString);
          if(stateIsIdent(state)) {
              state = matchIdToKeyword(currentTokenString);
          }
          struct token *myToken = new struct token;
          myToken->tokenId = state;
          myToken->tokenName = getTokenName(state);
          myToken->matchingString = currentTokenString;
          myToken->lineNumber = currentLineNumber;
          state = BEGIN_STATE;
          locationInString--; 
          lastStateNotFinal = false;
          return myToken;
      }
      if(state == FSA_ERROR) {
         struct token *myToken = new struct token;
         myToken->tokenId = FSA_ERROR;
         return myToken;
      }
      if(lastStateNotFinal) {
          if(inputString.at(locationInString) == '\n') {
              currentLineNumber++;
          }
          currentTokenString += inputString[locationInString];
      }

      lastStateNotFinal = true;
      locationInString++;
  }

}

int getCharacterColumn(char myChar) {
    int asciiChar = (int) myChar;

    if(isNewLine(asciiChar)) return NEWLINE_WHITESPACE_COL;
    else if(isWhiteSpace(asciiChar)) return NEWLINE_WHITESPACE_COL;
    else if(isDigit(asciiChar)) return DIGIT_COL;
    else if(isLetter(asciiChar)) return LETTER_COL;
    else if(isEqSign(asciiChar)) return EQUALS_COL;
    else if(isLessThan(asciiChar)) return LESS_COL;
    else if(isGreaterThan(asciiChar)) return GREATER_COL;
    else if(isExclPoint(asciiChar)) return EXCLPOINT_COL;
    else if(isColon(asciiChar)) return COLON_COL;
    else if(isPlus(asciiChar)) return PLUS_COL;
    else if(isMinus(asciiChar)) return MINUS_COL;
    else if(isStar(asciiChar)) return STAR_COL;
    else if(isSlash(asciiChar)) return SLASH_COL;
    else if(isAmper(asciiChar)) return AMP_COL;
    else if(isPercent(asciiChar)) return PERCENT_COL;
    else if(isPeriod(asciiChar)) return PERIOD_COL;
    else if(isLParens(asciiChar)) return LPARENS_COL;
    else if(isRParens(asciiChar)) return RPARENS_COL;
    else if(isComma(asciiChar)) return COMMA_COL;
    else if(isLBrace(asciiChar)) return LBRACE_COL;
    else if(isRBrace(asciiChar)) return RBRACE_COL;
    else if(isSemiColon(asciiChar)) return SEMICOLON_COL;
    else if(isLBracket(asciiChar)) return LBRACKET_COL;
    else if(isRBracket(asciiChar)) return RBRACKET_COL;
    else if(isCommentTag(asciiChar)) return COMMENT_TAG;
    else return BAD_CHARACTER;
}

string getTokenName(int token) {
   for(int i = 0; i < TokenArraySize; i++) {
      if(token == tokenID[i]) {
          return tokenName[i];
      }
   } 
}

int matchIdToKeyword(string currentIdentifier) {
  for(int i = 0; i < KeywordsSize; i++) {
    if((currentIdentifier.compare(Keywords[i])) == 0) {
      return tokenID[i];
    }
  }
  return 1037;
}

bool stateIsIdent(int token) {
    return token == 1037 ? true : false;
}

string cleanTokenString(string ident) {
    for(int i = 0; i < ident.size(); i++) {
        if(ident.at(i) == ' ' || ident.at(i) == '\n') {
            ident.erase(i, 1);
        }
    }
    return ident;
}

void printToken(token myToken) {
    cout << "Token ID: " << myToken.tokenId << endl;
    cout << "Token Name: " << myToken.tokenName << endl;
    cout << "Matching String: " << myToken.matchingString << endl;
    cout << "Line Number: " << myToken.lineNumber << endl;
}

int isNewLine(int asciiChar) {
    return asciiChar == NEWLINE_CHARACTER ? WHITESPACE_CHARACTER : 0;
}

int isWhiteSpace(int asciiChar) {
    return asciiChar == WHITESPACE_CHARACTER ? WHITESPACE_CHARACTER : 0;
}

int isDigit(int asciiChar) {
    return (START_DIGIT <= asciiChar && asciiChar <= END_DIGIT) ? DIGIT_COL : 0;
}

int isLetter(int asciiChar) {
    return (START_UPPER_LETTER <= asciiChar && asciiChar <= END_UPPER_LETTER) ||
           (START_LOWER_LETTER <= asciiChar && asciiChar <= END_LOWER_LETTER) ? LETTER_COL : 0;
}
int isEqSign(int asciiChar) {
  return asciiChar == EQ ? EQ : 0;
}

int isLessThan(int asciiChar) {
  return asciiChar == LESS ? LESS : 0;
}

int isGreaterThan(int asciiChar) {
  return asciiChar == GREATER ? GREATER : 0;
}

int isExclPoint(int asciiChar) {
  return asciiChar == EXCLPOINT ? EXCLPOINT : 0;
}

int isColon(int asciiChar) {
  return asciiChar == COLON ? COLON : 0;
}

int isPlus(int asciiChar) {
  return asciiChar == PLUS ? PLUS : 0;
}

int isMinus(int asciiChar) {
  return asciiChar == MINUS ? MINUS : 0;
}

int isStar(int asciiChar) {
  return asciiChar == STAR ? STAR : 0;
}

int isSlash(int asciiChar) {
  return asciiChar == SLASH ? SLASH : 0;
}

int isAmper(int asciiChar) {
  return asciiChar == AMP ? AMP : 0;
}

int isPercent(int asciiChar) {
  return asciiChar == PERCENT ? PERCENT : 0;
}

int isPeriod(int asciiChar) {
  return asciiChar == PERIOD ? PERIOD : 0;
}

int isLParens(int asciiChar) {
  return asciiChar == LPARENS ? LPARENS : 0;
}

int isRParens(int asciiChar) {
  return asciiChar == RPARENS ? RPARENS : 0;
}

int isComma (int asciiChar) {
  return asciiChar == COMMA ? COMMA : 0;
}

int isLBrace(int asciiChar) {
  return asciiChar == LBRACE ? LBRACE : 0;
}

int isRBrace(int asciiChar) {
  return asciiChar == RBRACE ? RBRACE : 0;
}

int isSemiColon(int asciiChar) {
  return asciiChar == SEMICOLON ? SEMICOLON : 0;
}

int isLBracket(int asciiChar) {
  return asciiChar == LBRACKET ? LBRACKET : 0;
}

int isRBracket(int asciiChar) {
  return asciiChar == RBRACKET ? RBRACKET : 0;
}

int isCommentTag(int asciiChar) {
  return asciiChar == COMMENT_TAG ? COMMENT_TAG : 0;
}
