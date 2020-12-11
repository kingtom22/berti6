#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	unsigned value;
	struct Node* next;
}Node;

typedef struct Queue
{
	Node* front;
	Node* back;
}Queue;

int initialize(Queue* FIFO)
{
	FIFO->front = NULL;
	FIFO->back = NULL;
}
int enqueue(Queue* FIFO, Node newNode)
{
	if (!FIFO->front)
	{
		FIFO->front = malloc(sizeof(Node));
		FIFO->front->next = NULL;
		FIFO->front->value = NULL;
		FIFO->back = malloc(sizeof(Node));
	}
	FIFO->back->next = newNode.next;
	FIFO->back->value = newNode.value;
}
int main()
{
	Queue FIFO;
	initialize(&FIFO);
	printf("szevasz\n");

	Node n;
	n.next = NULL;
	n.value = NULL;
	enqueue(&FIFO, n);
	printf("lépegetõ kutyafasz\n");
	printf("%d\n", FIFO.front->value);

	return 0;
}
