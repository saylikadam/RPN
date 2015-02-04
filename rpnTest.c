#include "rpn.h"
#include "expr_assert.h"
#include "string.h"

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

void test_evaluate_returns_the_result_of_postfix_complex_expression_of_2_2_2_2_3(){
	int result = evaluate("2 2 2 * 2 - 3 + + ");
	assertEqual(result, 7);
}
void test_evaluate_returns_the_result_of_postfix_complex_expression_of_2_2_2_2_2_2_2(){
	int result = evaluate("2 2 2 2 2 * * 2 + + 2 - *");
	assertEqual(result, 20);
}	

void test_evaluate_returns_the_result_of_postfix_complex_expression_of_2_2_2_2_2_2(){
	int result = evaluate("2 2 - 2 2 2 * 2 - - -");
	assertEqual(result, 0);
}

void test_evaluate_returns_the_result_of_postfix_complex_expression_of_5_1_2_4_3(){
	int result = evaluate("5 1 2 + 4 * + 3 -");
	assertEqual(result, 14);
}

// void test_evaluate_returns_the_result_with_errorValue_1_when_wrong_expression_isPassed(){
// 	int result = evaluate("5 4 1 + 4 * + 3 5 -");
// 	assertEqual(result.error, 1);
// 	assertEqual(result, 0);
// }

// void test_evaluate_returns_the_result_with_error_having_1_for_less_number_of_operands(){
// 	int result = evaluate("1 + - 4 * + 5 -");
// 	assertEqual(result.error, 1);
// }

// void test_evaluate_returns_the_result_with_error_having_1_for_less_number_of_operators(){
// 	int result = evaluate("1 3 5 4 * + 5 -");
// 	assertEqual(result.error, 1);

// void test_evaluate_returns_the_result_of_postfix_operation_for_multi_digit_operands (){
// 	assertEqual(evaluate("20 4 *"),80);
// 	assertEqual(evaluate("20000 400 +"),20400);
// }
