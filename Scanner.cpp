#include "Scanner.h"
#include "Token.h"
using namespace std;

string fileName, line, inputString;
char myChar;
fstream file;
string extension = ".fs16";
string preName = "out";

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
            file.get(myChar);

            //Exit immediately if a bad character is found
            if(checkIfValidCharacter(myChar) == BAD_CHARACTER) {
                return BAD_CHARACTER;
            }

            //If the '@' symbol is found for comments, continue on till
            //white space so as not to include the comments in the processing
            if((int) myChar == ASCII_BEGIN_COMMENT) {
                do {
                    file.get(myChar);

                    //if comment goes until last line, break
                    if(file.eof()) {
                        break;
                    }
                } while((int) myChar != ASCII_WHITESPACE);
            }

            //Add all valid characters to the string
            if(!file.eof()) {
                inputString += myChar;
            }
        }
        file.close();
    }

    //If the user is using std input, parse the input and add it to the
    //the input string
    else {

        while(!cin.eof()) {
            cin.get(myChar);

            //Exit immediately if a bad character is found
            if(checkIfValidCharacter(myChar) == BAD_CHARACTER) {
                return BAD_CHARACTER;
            }

            //If the '@' symbol is found for comments, continue on till
            //white space so as not to include the comments in the processing
            if((int) myChar == ASCII_BEGIN_COMMENT) {
                do {
                    cin.get(myChar);

                    //if comment goes until last line, break
                    if(cin.eof()) {
                        break;
                    }
                } while((int) myChar != ASCII_WHITESPACE);
            }

            //Add all valid characters to the string
            if(!cin.eof()) {
                inputString += myChar;
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

    if(asciiChar < 10 || (10 < asciiChar && asciiChar < 32) || (33 < asciiChar && asciiChar < 36) ||
       asciiChar == 39 || asciiChar == 63 || asciiChar == 92 || (93 < asciiChar && asciiChar < 97) ||
       asciiChar == 124 || 125 < asciiChar) {
            cout << "Found bad character " << myChar << endl;
            return BAD_CHARACTER;
       }
    else {
        return GOOD_CHARACTER;
    }
}


