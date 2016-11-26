#ifndef STACK_H
#define STACK_H
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class Stack {
  private:
    struct Node {
      string value;
      Node *next;
    };

    Node *top;

  public:
    Stack() {
      top = NULL;
    }
    void push(string);
    void pop(void);
    int find(string);
  

};




#endif
