#include "LinkedList.h"

typedef struct queue{
	LinkedList *list;	
}Queue;

Queue createQueue(void);
int Enqueue(Queue,void*);
void *Dequeue(Queue);