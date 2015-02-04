#include "rpn.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//it will create stack for the elements of expression 2 3 +
int operator(char op){
	if(op == '+' || op == '-' || op == '*' || op == '/')
		return 1;
	return 0;
}

Stack stackElements(char *expression){
	int length = strlen(expression);
	int i ,*result,store[5],j=0;
	Stack s = createStack();

	for(i = 0;i<length;i++){
		if(expression[i] == ' '){
			continue;
		}
		if( isdigit(expression[i]) ){
			result = malloc( sizeof(int));
			*result = atoi(&expression[i]);
			push(&s,result);
		}
	}
	return s;
}
int calculator(int a,int b,char expression){
	int result ;
	switch(expression){
		case '+': result =  a+b;break;
		case '-': result =  b-a;break;
		case '*': result =  a*b;break;
		case '/': result =  b/a;break;
		default : result = -1;
	}
	return result;
}
// got expression ,need to separate it char by char n then evaluation

int evaluate(char *expression){
	Stack s = stackElements(expression);
	int i,a,b ,*result;
	int length = strlen(expression);

	for(i=0; i<length; i++){
		if(operator(expression[i])){

			a = *(int*)pop(&s);
			b = *(int*)pop(&s);	
			
			result = malloc( sizeof(int));
			*result = calculator(a,b,expression[i]);

			push(&s,result);
		}
	}		
	return *result;
}