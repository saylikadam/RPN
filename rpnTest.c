#include "rpn.h"
#include "expr_assert.h"
#include "string.h"

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

// void test_evaluate_returns_the_result_of_postfix_operation_for_multi_digit_operands (){
// 	assertEqual(evaluate("20 4 *"),80);
// 	assertEqual(evaluate("20000 400 +"),20400);
// }
