#include "Scanner.h"
#include "Token.h"
using namespace std;

string fileName, line, inputString;
char myChar;
ifstream file;
string extension = ".fs16";
string preName = "out";

int processData(char *argv[], int argc) {

   inputString = "";

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

        while(!file.eof()) {
            file.get(myChar);
            inputString += myChar;
        }
        file.close();
    }

    else {

        while(!cin.eof()) {
            cin.get(myChar);
            inputString += myChar;
        }
    }

    return scan(inputString);

}

int scan(string inputString) {

    cout << inputString << endl;
    return 0;
}
