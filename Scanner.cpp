#include "Scanner.h"
#include "Token.h"
using namespace std;

string fileName, line, inputString;
fstream file;
string extension = ".fs16";
string preName = "out";

int processData(char ** argv, int argc) {
   

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

        file.open(fileName.c_str());

        if(!file) {
            perror("Error opening file");
            exit(1);
        }
        while(getline (file, line)) {
            cout << line << endl;
            inputString.append(line);
        }
        file.close();
    }

    else {
        fileName = preName;

        while(getline(cin, line)) {
            inputString.append(line);
        }
    }

    cout << inputString << endl;
    return 0;

}


