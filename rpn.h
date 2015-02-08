#include "../StackADT/stack.h"

typedef struct result Result;

struct result {
  int error;
  int status;
};


Result evaluate(char *expression); 
Stack stackElements(char *expression);
char * infixToPostfix(char * expression);
int operator(char);
int calculator(int,int,char);
void performIfDigit(char expression, Stack *s);

