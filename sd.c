int operation(char op){
	if(op == '+' || op == '-' || op == '*' || op == '/')
		return 1;
	return 0;
} 

Stack giveOperands(*expression){
	int length = strlen(expression),i,*result;
	// printf("%d\n",(int)expression );
	// Stack s = createStack();
	// for(i=0;i<length;i++){
		// if(expression[i] != ' '){
		// 	*result = atoi(&expression[i]);
		// }
	// }
	
}


int evaluate(char *expression){
	//Stack s = giveOperands(expression);
     printf("%s\n",expression );
	// int result ,operand1,operand2;
	// int length = strlen(expression),i;
	
	// for(i = 0; i < length; i++){
	// 	if(expression[i] != ' '){
	// 		result = atoi(&expression[i]);
	// 		push(&s,&result);
	// 	}
	// operand2 = (int)pop(&s);
	// operand1 = (int)pop(&s);
	// printf("%d\n",operand2 );
	}


// }

/*if(operation(expression[i])){
				result = atoi(expression[i]);
				printf("----------->>>>%d\n",result);
				// push(&s,&expression[i]);
			}*/

				// for(i = 0; i<length; i++){
	// 	// if( operator(expression[i]) ){
	// 	//     store[j++] = expression[i];
	// 	// 	continue;
	// 	// }

	// 	if(expression[i] == ' '){
	// 		break;
	// 	}
	// 		// continue;
	// 	result = atoi(&expression[i]);
	// 	printf("------------>>%d\n",result );
	// 	push(&s,&result);

	// 	// if()
	// }

	// for(i=0;i<j;i++){
	// 	push(&s,&store[i]);
	// }