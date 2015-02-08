#include "rpn.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int calculator(int operand1,int operand2,char expression){
	switch(expression){
		case '+': return operand1 + operand2;break;
		case '-': return operand2 - operand1;break;
		case '*': return operand1 * operand2;break;
		case '/': return operand2 / operand1;break;
		default : return -1;
	}
}

int operator(char op){
	if(op == '+' || op == '-' || op == '*' || op == '/')
		return 1;
	return 0;
}
void performIfDigit(char expression, Stack *s){
	int *result;
	result = malloc( sizeof(int));
	*result = atoi(&expression);
	push( s,result);
}

Stack stackElements(char *expression){
	int length = strlen(expression) ,i;
	Stack s = createStack();

	for(i = 0;i<length;i++){
		if(expression[i] == ' '){
			continue;
		}
		if( isdigit(expression[i]) ){
			performIfDigit(expression[i],&s);
		}
		else
			if(operator(expression[i])){
				break;
			}
	}
	return s;
}

int forWrongInput(char *expression,int length){
	int operator_count = 0,operand_count =0,j;
	for(j=0;j<length;j++){
		if(isdigit(expression[j])){
			operand_count++;
		}
		if(operator(expression[j]))
			operator_count++;
	}
	return (operand_count != operator_count + 1);
}

void popElement(char expression,Stack *s,int *result){
	int operand1,operand2;
	operand1 = *(int*)pop(s);
	operand2 = *(int*)pop(s);
	*result = calculator(operand1,operand2,expression);
	push(s,result);
}

Result evaluate(char *expression){
	Result answer = {0,0};
	Stack s = stackElements(expression);
	int *result = malloc( sizeof(int));
	int length = strlen(expression) ,i;

	if(forWrongInput(expression,length)) return (Result){1,0};
	for(i=0; i<length; i++){
		if(isdigit(expression[i])){
			performIfDigit(expression[i],&s);
			continue;
		}
		if(operator(expression[i])) 
			popElement(expression[i],&s,result);
	}
	answer.status = *result;		
	return  answer;
}

