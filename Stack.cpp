#include "Stack.h"

void Stack::push(string str) {
  Node *newNode = new Node();
  newNode->value = str;

  if(top == NULL) {
    top = newNode;
    top->next = NULL;
  }
  else {
    newNode->next = top;
    top = newNode;
  }
}

void Stack::pop() {
  cout << "Popping " << top->value << endl;
  Node *temp;
  temp = top->next;
  delete top;
  top = temp;
}

int Stack::find(string str) {
  int location = 0;
  Node *temp = top;
  while(temp) {
    if(temp->value == str) {
      cout << "\nFound Var " << str << " at location " << location << endl;
      return location; 
    }
    location++;
    temp = temp->next;
  }
  cout << "\nFound Var " << str << " at location " << -1 << endl;
  return -1;

}
