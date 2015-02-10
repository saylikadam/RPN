#include <stdio.h>
typedef void TestFn(void);
typedef struct{
	char* name; 
	TestFn* fn;
} Test;

//code to be updated starts
TestFn setup,teardown,fixtureSetup,fixtureTearDown,test_operator_gives_1_if_given_char_is_an_operator,test_calculator_gives_result_of_calculation_of_operands,test_performIfDigits_will_take_char_value_and_convert_into_integer_and_store_it_into_stack,test_evaluate_will_simplify_the_operation,test_evaluate_returns_the_result_of_postfix_operation,test_evaluate_returns_the_results_of_postfix_operation2,test_evaluate_returns_the_results_of_postfix_operation3,test_evaluate_returns_the_result_of_postfix_operation_for_multiple_operators,test_evaluate_returns_the_result_of_postfix_operation_for_multiple_operators2,test_evaluate_returns_the_result_of_postfix_operation_for_multiple_operators3,test_evaluate_works_fine_with_numbers_not_seperated_by_spaces,test_evaluate_returns_the_result_of_postfix_complex_expression_of_2_2_2_2_3,test_evaluate_returns_the_result_of_postfix_complex_expression_of_2_2_2_2_2_2_2,test_evaluate_returns_the_result_of_postfix_complex_expression_of_2_2_2_2_2_2,test_evaluate_returns_the_result_of_postfix_complex_expression_of_5_1_2_4_3,test_evaluate_returns_the_result_with_errorValue_1_when_wrong_expression_isPassed,test_evaluate_returns_the_result_with_error_having_1_for_less_number_of_operands,test_evaluate_returns_the_result_with_error_having_1_for_less_number_of_operators,test_infixToPostfix_returns_the_postfix_of_the_prefix_operation;
Test test[] = {"test_operator_gives_1_if_given_char_is_an_operator",test_operator_gives_1_if_given_char_is_an_operator,"test_calculator_gives_result_of_calculation_of_operands",test_calculator_gives_result_of_calculation_of_operands,"test_performIfDigits_will_take_char_value_and_convert_into_integer_and_store_it_into_stack",test_performIfDigits_will_take_char_value_and_convert_into_integer_and_store_it_into_stack,"test_evaluate_will_simplify_the_operation",test_evaluate_will_simplify_the_operation,"test_evaluate_returns_the_result_of_postfix_operation",test_evaluate_returns_the_result_of_postfix_operation,"test_evaluate_returns_the_results_of_postfix_operation2",test_evaluate_returns_the_results_of_postfix_operation2,"test_evaluate_returns_the_results_of_postfix_operation3",test_evaluate_returns_the_results_of_postfix_operation3,"test_evaluate_returns_the_result_of_postfix_operation_for_multiple_operators",test_evaluate_returns_the_result_of_postfix_operation_for_multiple_operators,"test_evaluate_returns_the_result_of_postfix_operation_for_multiple_operators2",test_evaluate_returns_the_result_of_postfix_operation_for_multiple_operators2,"test_evaluate_returns_the_result_of_postfix_operation_for_multiple_operators3",test_evaluate_returns_the_result_of_postfix_operation_for_multiple_operators3,"test_evaluate_works_fine_with_numbers_not_seperated_by_spaces",test_evaluate_works_fine_with_numbers_not_seperated_by_spaces,"test_evaluate_returns_the_result_of_postfix_complex_expression_of_2_2_2_2_3",test_evaluate_returns_the_result_of_postfix_complex_expression_of_2_2_2_2_3,"test_evaluate_returns_the_result_of_postfix_complex_expression_of_2_2_2_2_2_2_2",test_evaluate_returns_the_result_of_postfix_complex_expression_of_2_2_2_2_2_2_2,"test_evaluate_returns_the_result_of_postfix_complex_expression_of_2_2_2_2_2_2",test_evaluate_returns_the_result_of_postfix_complex_expression_of_2_2_2_2_2_2,"test_evaluate_returns_the_result_of_postfix_complex_expression_of_5_1_2_4_3",test_evaluate_returns_the_result_of_postfix_complex_expression_of_5_1_2_4_3,"test_evaluate_returns_the_result_with_errorValue_1_when_wrong_expression_isPassed",test_evaluate_returns_the_result_with_errorValue_1_when_wrong_expression_isPassed,"test_evaluate_returns_the_result_with_error_having_1_for_less_number_of_operands",test_evaluate_returns_the_result_with_error_having_1_for_less_number_of_operands,"test_evaluate_returns_the_result_with_error_having_1_for_less_number_of_operators",test_evaluate_returns_the_result_with_error_having_1_for_less_number_of_operators,"test_infixToPostfix_returns_the_postfix_of_the_prefix_operation",test_infixToPostfix_returns_the_postfix_of_the_prefix_operation};
char testFileName[] = {"rpnTest.c"};
void _setup(){/*CALL_SETUP*/}
void _teardown(){/*CALL_TEARDOWN*/}
void fixtureSetup(){}
void fixtureTearDown(){}
//code to be updated ends

int testCount;
int passCount;
int currentTestFailed;

int assert_expr(int expr, const char* fileName, int lineNumber, const char* expression){
	if(expr) return 0;
	currentTestFailed = 1;
	printf("\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
	return 1;
}
int assert_equal(int val1, int val2, const char* fileName, int lineNumber,const char* expr1,const char* expr2){
	if(val1 == val2) return 0;
	currentTestFailed = 1;
	printf("\t %d == %d: failed in assertEqual(%s,%s) at %s:%d\n",val1,val2,expr1,expr2, fileName,lineNumber);
	return 1;
}

void runTest(char* name, TestFn test){
	testCount++,currentTestFailed=0;
	printf("**  %s\n",name);
	_setup();
		test();
	_teardown();
	if(!currentTestFailed) passCount++;	
}
int main(int argc, char const *argv[]){		
	int i,total = sizeof(test)/sizeof(Test);	
	fixtureSetup();
	testCount=0,passCount=0;
	printf("**------ %s ------\n",testFileName);
	for (i = 0; i < total; ++i)
		runTest(test[i].name,test[i].fn);	
	printf("** Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
	fixtureTearDown();	
	return 0;
}