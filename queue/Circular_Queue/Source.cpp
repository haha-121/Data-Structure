#include<iostream>

#define MAX 7
int front= MAX - 1, rear = MAX - 1;
void push(int **q,const int n);
void pop(int **q);
void show(int *q);
int main()
{
	printf("queue size is %d-%d=%d\n\n", MAX, 1, MAX - 1);
	int* queue=(int*)calloc(MAX,sizeof(int));
	show(queue);
	push(&queue, 10);
	push(&queue, 20);
	push(&queue, 30);
	push(&queue, 40);
	push(&queue, 50);
	show(queue);

	pop(&queue);
	show(queue);

	pop(&queue);
	pop(&queue);
	show(queue);

	push(&queue, 60);
	push(&queue, 70);
	push(&queue, 80);
	push(&queue, 90);
	push(&queue, 100);
	show(queue);


	free(queue);
	return 0;
}
void push(int** q,const int n)
{
	if ((rear+1)%MAX==front)
		printf("Queue is full\n");
	else
	{
		rear = (rear + 1) % MAX;
		*(*q+rear) = n;
		printf("Data %d push\n",n);
	}
}
void pop(int** q)
{
	if (front == rear)
		printf("Queue is empty\n");
	else
	{
		front = (front + 1) % MAX;
		printf("Data %d pop\n",*(*q + front));
		*(*q + front) = 0;
	}
}
void show(int* q)
{
	if (front != rear)
	{
		int head = (front+1) % MAX;

		while (q[head] != 0)
		{
			printf("%d ",q[head]);
			head = (head + 1) % MAX;
		}
		printf("\n\n");
	}
	else
		printf("Queue is empty\n");
}
