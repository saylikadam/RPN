#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


Queue createQueue(){
	Queue q;
	q.list = calloc(1,sizeof(LinkedList));
	return q;
}


int Enqueue(Queue q1,void* data){
	Node* node = create_node(data);
	add_to_list(q1.list, node);
	return q1.list->count;
}

void *Dequeue(Queue q1){
	return deleteElementAt(q1.list, 0);
}


