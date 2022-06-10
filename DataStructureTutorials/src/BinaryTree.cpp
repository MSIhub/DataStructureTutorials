#include "BinaryTree.h"

void Queue::enqueue(Node * x)
{
	if (rear == size - 1)
		printf("Queue Full\n");
	else
	{
		rear++;
		Q[rear] = x;
	}
}

