#include "Scanner.h"

using namespace std;
string fileName, line, numberString;
fstream file;
string data = ".fs16";
string preName = "out";

int processData(char ** argv, int argc) {
   

	if(argc > 1) {
        preName = argv[1];
        size_t found = preName.find(data);

        if(found > preName.size()) {
          fileName = preName + data;
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
            numberString.append(line);
        }
        file.close();
    }

    else {
        fileName = preName;

        while(getline(cin, line)) {
            numberString.append(line);
        }
    }

  return 0;

}


