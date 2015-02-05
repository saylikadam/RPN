#include "rpn.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

//it will create stack for the elements of expression 2 3 +
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
	int length = strlen(expression);
	int i ,a,b,*result,store[5],j=0;
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
	int i,a,b ,*result;
	int length = strlen(expression);

	if(forWrongInput(expression,length)){
		answer.error = 1;
		answer.status = 0;
		return answer;
	}
	for(i=0; i<length; i++){
		if(isdigit(expression[i])){
			result = malloc( sizeof(int));
			*result = atoi(&expression[i]);
			push(&s,result);
			continue;
		}
		if(operator(expression[i])){
			a = *(int*)pop(&s);
			b = *(int*)pop(&s);	
			result = malloc( sizeof(int));
			*result = calculator(a,b,expression[i]);
			push(&s,result);
		}	
	}
	answer.status = *(int*)result;		
	return  answer;
}