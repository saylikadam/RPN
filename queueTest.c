#include "queue.h"
#include "expr_assert.h"
#include <stdio.h>
// #include "string.h"

#define log(test_description) int log = printf("**  Description->%s\n\n", test_description)


void test_add_will_return_4_for_2_2_values(){
	log("adding 2 + 2");
	assert((2+2) == 4);
}

void test_createQueue_01(){
	log("create queue will create a empty queue");
	Queue q1 = createQueue();
	assertEqual(q1.list->count,0);
	assertEqual((int)q1.list->head,0);
	assertEqual((int)q1.list->tail,0);
}

void test_createQueue_02(){
	log("create queue will create a empty queue");
	Queue q1 = createQueue();
	assertEqual(q1.list->count,0);
	assertEqual((int)q1.list->head,0);
	assertEqual((int)q1.list->tail,0);
}

void test_Enqueue(){
	log("enqueue will insert element into queue");
	int data = 10;
	Queue q1 = createQueue();
	assertEqual(Enqueue(q1, &data),1);
	assertEqual(*(int*)q1.list->tail->std_id,10);
}

void test_Dequeue(){
	log("dequeue will delete element from queue");
	Queue q1 = createQueue();
	assertEqual((int)Dequeue(q1),0);
}

