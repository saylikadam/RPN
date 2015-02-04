#include "rpn.h"
#include "expr_assert.h"
#include "string.h"

int evaluate(char *expression); 
void test_evaluate_will_simplify_the_operation(){
	int result;
	char *expression = "2 3 +";
	result = evaluate(expression);
	assertEqual(result,5);
}

void test_evaluate_returns_the_result_of_postfix_operation (){
	assertEqual(evaluate("2 4 +"),6);
	assertEqual(evaluate("2 4 *"),8);
	assertEqual(evaluate("2 4 -"),-2);
	assertEqual(evaluate("4 2 /"),2);
}

void test_evaluate_returns_the_result_of_postfix_operation_for_multiple_operators (){
	assertEqual(evaluate("2 4 6 + *"),20);
	assertEqual(evaluate("5 4 6 5 + + -"),-10);
	assertEqual(evaluate("5 4 6 5 8 2 + + + ++"),30);
}

void test_evaluate_works_fine_with_numbers_not_seperated_by_spaces (){
	assertEqual(evaluate("5 4+"),9);
}

// // void test_evaluate_returns_the_result_of_postfix_complex_expression_of_2_2_2_2_3(){
// // 	int result = evaluate("2 2 2 * 2 - 3 + + ");
// // 	assertEqual(result, 7);
// // }

// void test_evaluate_returns_the_result_of_postfix_operation_for_multi_digit_operands (){
// 	assertEqual(evaluate("20 4 *"),80);
// 	assertEqual(evaluate("20000 400 +"),20400);
// }
