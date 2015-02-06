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
void afterIsDigit(char expression){
	int *result;
	result = malloc( sizeof(int));
	*result = atoi(&expression);
	// push(&s,result);
}

Stack stackElements(char *expression){
	int i,*result,store[5],j=0;
	int length = strlen(expression);
	Stack s = createStack();

	for(i = 0;i<length;i++){
		if(expression[i] == ' '){
			continue;
		}
		if( isdigit(expression[i]) ){
			afterIsDigit(expression[i]);
			push(&s,result);
		}
		else
			if(operator(expression[i])){
				break;
			}
	}
	return s;
}

// got expression ,need to separate it char by char n then evaluation
int forWrongInput(char *expression,int length){
	int operator_count = 0,operand_count =0,j;
	for(j=0;j<length;j++){
		if(isdigit(expression[j])){
			operand_count++;
		}
		if(operator(expression[j]))
			operator_count++;
	}
	return (operand_count != operator_count+1)?1:0;
}

Result evaluate(char *expression){
	Result answer = {0,0};
	Stack s = stackElements(expression);
	int length = strlen(expression);
	int i,operand1,operand2 ,*result;

	if(forWrongInput(expression,length)) return (Result){1,0};
	
	for(i=0; i<length; i++){
		if(isdigit(expression[i])){
			// afterIsDigit(expression[i]);
			result = malloc( sizeof(int));
			*result = atoi(&expression[i]);
			push(&s,result);
			continue;
		}
		if(operator(expression[i])){

			operand1 = *(int*)pop(&s);
			operand2 = *(int*)pop(&s);	
			result = malloc( sizeof(int));
			*result = calculator(operand1,operand2,expression[i]);
			push(&s,result);
		}	
	}
	answer.status = *(int*)result;		
	return  answer;
}
