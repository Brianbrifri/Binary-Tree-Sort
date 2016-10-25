#include<cstdlib>
#include "Scanner.h"
#include "Token.h"

using namespace std;

int main(int argc, char *argv[]) {

    switch(processData(argv, argc)) {
        case BAD_CHARACTER:
            cout << "Exiting due to bad character\n";
            exit(BAD_CHARACTER);
        case FSA_ERROR:
            cout << "Exiting due to language error\n";
            exit(FSA_ERROR);
        case 0:
            cout << "Program exiting normally\n";
            break;
        default:
            cout << "Shouldn't reach here\n";
    }
		
    return 0;
}

