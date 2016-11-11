#include "treePrint.h"
#include <fstream>

void printTree(Node *node, int level, ofstream &file) {
  if(node) {
    cout << "checking node token: " << node->token1.tokenId << endl;
    if(node->token1.tokenId > 0) {
      for(int i = 0; i < level; i++) {
        cout << "  ";
        file << "  ";
      }
      cout << node->label << " ";
      file << node->label << " ";
      cout << node->token1.tokenId << " ";
      file << node->token1.tokenId << " ";
      cout << node->token1.tokenName << " ";
      file << node->token1.tokenName << " ";
      cout << node->token1.matchingString << " ";
      file << node->token1.matchingString << " ";
      cout << node->token1.lineNumber << "\n";
      file << node->token1.lineNumber << "\n";
      if(node->token2.tokenId > 0) {
        cout << node->label << " ";
        file << node->label << " ";
        cout << node->token2.tokenId << " ";
        file << node->token2.tokenId << " ";
        cout << node->token2.tokenName << " ";
        file << node->token2.tokenName << " ";
        cout << node->token2.matchingString << " ";
        file << node->token2.matchingString << " ";
        cout << node->token2.lineNumber << " ";
        file << node->token2.lineNumber << " ";
      }
    }
    printTree(node->child1, level + 1, file);
    printTree(node->child2, level + 1, file);
    printTree(node->child3, level + 1, file);
    printTree(node->child4, level + 1, file);
  }
}
