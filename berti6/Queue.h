#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	unsigned value;
	struct Node* next;
}Node, Iterator[1];

typedef struct Queue
{
	Node* front;
	Node* back;
}Queue;

// operations
bool initialize(Queue* FIFO);
void enqueue(Queue* FIFO, int num);
int dequeue(Queue* FIFO);
void empty(Queue* FIFO);

// queries
void display(Queue FIFO);
bool isEmpty(Queue FIFO);
int length(Queue FIFO);