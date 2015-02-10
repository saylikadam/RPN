#include "stack.h"
#include "Queue.h"
typedef struct result Result;
typedef char *String;
struct result {
  int error;
  int status;
};


Result evaluate(char *expression); 
Stack stackElements(char *expression);
int operator_(char);
int calculator(int,int,char);
void performIfDigit(char expression, Stack *s);

char * infixToPostfix(char * expression);