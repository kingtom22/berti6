#include "Queue.h"
#include <memory.h>
bool initialize(Queue* FIFO)
{
	FIFO->front = NULL;
	FIFO->back = NULL;

	return true;
}
void enqueue(Queue* FIFO, int num)
{
	if (!FIFO->front)
	{
		FIFO->front = (Node*)malloc(sizeof(Node));
		FIFO->front->next = NULL;
		FIFO->front->value = num;
		FIFO->back = FIFO->front;
	}
	else
	{
		Node* newBack = (Node*)malloc(sizeof(Node));
		newBack->next = FIFO->back;
		newBack->value = num;
		FIFO->back = newBack;
	}
}
int dequeue(Queue* FIFO)
{
	int ret = -1;
	if (FIFO->front)
	{
		if (FIFO->front == FIFO->back)
		{
			ret = FIFO->front->value;
			free(FIFO->front);
			initialize(FIFO);
		}
		else
		{
			ret = FIFO->front->value;
			Node* it = FIFO->back;
			Node* prev;
			while (it != FIFO->front)
			{
				prev = it;
				it = it->next;
			}
			FIFO->front = prev;
		}
	}
	return ret;
}
void empty(Queue * FIFO)
{
	while (FIFO->back != FIFO->front)
	{
		dequeue(FIFO);
	}
	free(FIFO->front);
	initialize(FIFO);
}
void display(Queue FIFO)
{
	//printf("front: %d\n", FIFO.front->value);
	//printf("back: %d\n\n", FIFO.back->value);
	if (FIFO.back == NULL)
	{
		printf("The queue is empty!\n\n");
	}
	else if(FIFO.back == FIFO.front)
	{
		printf("%d -> nil\n\n", FIFO.front->value);
	}
	else
	{
		Node* it = FIFO.back;
		while (it != FIFO.front)
		{
			printf("%d -> ", it->value);
			it = it->next;
		}
		printf("%d -> nil\n\n", FIFO.front->value);
	}
}

bool isEmpty(Queue FIFO)
{
	if (FIFO.front == NULL)
		return true;
	return false;
}

int length(Queue FIFO)
{
	if (!isEmpty(FIFO))
	{
		unsigned count = 1;
		Node* it = FIFO.back;
		while (it != FIFO.front)
		{
			count++;
			it = it->next;
		}
		return count;
	}
	return 0;
}
