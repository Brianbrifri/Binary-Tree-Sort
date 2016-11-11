#include "treePrint.h"

void printTree(Node *node, int level, ofstream &file) {
  if(node) {
    if(node->token1.tokenId != -1) {
      for(int i = 0; i < level; i++) {
        std::cout << "  ";
      }
    }
  }

}
