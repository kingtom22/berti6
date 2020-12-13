#include "Queue.h"

int main()
{
	Queue FIFO;
	initialize(&FIFO);

	enqueue(&FIFO, 1);
	printf("len: %d\n", length(FIFO));
	display(FIFO);

	enqueue(&FIFO, 2);
	printf("len: %d\n", length(FIFO));
	display(FIFO);

	enqueue(&FIFO, 93);
	printf("len: %d\n", length(FIFO));
	empty(&FIFO);
	display(FIFO);

	dequeue(&FIFO);
	display(FIFO);

	dequeue(&FIFO);
	display(FIFO);

	dequeue(&FIFO);
	display(FIFO);

	return 0;
}
