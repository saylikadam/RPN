#include "rpn.h"
#include "expr_assert.h"
#include "string.h"

void test_operator_gives_1_if_given_char_is_an_operator(){
	assert(operator_('+') ==1);
	assert(operator_('^') ==0);
}
void test_calculator_gives_result_of_calculation_of_operands(){
	assert(calculator(3,4,'+') == 7);
	assert(calculator(3,4,'-') == 1);
	assert(calculator(3,4,'*') == 12);
	assert(calculator(2,4,'/') == 2);
}
// void performIfDigit(char expression, Stack *s){

void test_performIfDigits_will_take_char_value_and_convert_into_integer_and_store_it_into_stack(){
	Stack s = createStack();
	char value = '3';
	// isdigit(value);
	performIfDigit(value, &s);
	assertEqual((int)s.size,1);
	assertEqual((int)s.top->next,0);
	// printf("%d\n",*(int*)s.top->std_id );
	// assertEqual(*(int*)s.top->std_id,2);
}

void test_evaluate_will_simplify_the_operation(){
	Result result = evaluate("2 3 +");
	assertEqual(result.status,5);
}

void test_evaluate_returns_the_result_of_postfix_operation (){
	Result result = evaluate("2 4 -");
	assertEqual(result.status,-2);
}

void test_evaluate_returns_the_results_of_postfix_operation2(){
	Result result2  = evaluate("2 4 *");
	assertEqual(result2.status,8);
}

void test_evaluate_returns_the_results_of_postfix_operation3(){
	Result result3  = evaluate("4 2 /");
	assertEqual(result3.status,2);
}

void test_evaluate_returns_the_result_of_postfix_operation_for_multiple_operators (){	
	Result result3 = evaluate("5 4 6 5 8 2 + + + ++"); 
	assertEqual(result3.status,30);
}

void test_evaluate_returns_the_result_of_postfix_operation_for_multiple_operators2(){
	Result result = evaluate("2 4 6 + *");
	assertEqual(result.status,20);
}

void test_evaluate_returns_the_result_of_postfix_operation_for_multiple_operators3(){
	Result result2 = evaluate("5 4 6 5 + + -");
	assertEqual(result2.status,-10);
}


void test_evaluate_works_fine_with_numbers_not_seperated_by_spaces (){
	Result result = evaluate("5 4 +");
	assertEqual(result.status,9);
}

void test_evaluate_returns_the_result_of_postfix_complex_expression_of_2_2_2_2_3(){
	Result result = evaluate("2 2 2 * 2 - 3 + + ");
	assertEqual(result.status, 7);
}
void test_evaluate_returns_the_result_of_postfix_complex_expression_of_2_2_2_2_2_2_2(){
	Result result = evaluate("2 2 2 2 2 * * 2 + + 2 - *");
	assertEqual(result.status, 20);
}	

void test_evaluate_returns_the_result_of_postfix_complex_expression_of_2_2_2_2_2_2(){
	Result result = evaluate("2 2 - 2 2 2 * 2 - - -");
	assertEqual(result.status, 0);
}

void test_evaluate_returns_the_result_of_postfix_complex_expression_of_5_1_2_4_3(){
	Result result = evaluate("5 1 2 + 4 * + 3 -");
	assertEqual(result.status, 14);
}

void test_evaluate_returns_the_result_with_errorValue_1_when_wrong_expression_isPassed(){
	Result result = evaluate("5 4 1 + 4 * + 3 5 -");
	assertEqual(result.error, 1);
	assertEqual(result.status, 0);
}

void test_evaluate_returns_the_result_with_error_having_1_for_less_number_of_operands(){
	Result result = evaluate("1 + - 4 * + 5 -");
	assertEqual(result.error, 1);
}

void test_evaluate_returns_the_result_with_error_having_1_for_less_number_of_operators(){
	Result result = evaluate("1 3 5 4 * + 5 -");
	assertEqual(result.error, 1);
}

// char * infixToPostfix(char * expression);

void test_infixToPostfix_returns_the_postfix_of_the_prefix_operation(){
	char *s1 = "2 + 3";
	char *s2 = "2 3 +";
	assertEqual(strcmp(infixToPostfix(s1),s2),0);
}