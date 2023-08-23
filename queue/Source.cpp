#include<stdlib.h>
#include<stdio.h>

int front = 0,rear = -1;
#define MAX 10
int queue[MAX];
void insert(int n);
void remove();
void list();
int main()
{
	insert(10);
	list();
	insert(20);
	list();
	insert(30);
	list();
	remove();
	list();
	remove();
	list();
	insert(40);
	list();
	return 0;
}
void insert(int n)
{
	if (rear == MAX - 1)
		printf("queue full\n");
	else
	{
		printf("data %d inserted\n",n);
		queue[++rear] = n;
	}
}
void remove()
{
	if (rear < front)
		printf("queue no data\n");
	else
		printf("data %d removed\n",queue[front++]); 
}
void list()
{
	for (int i = front; i <= rear; i++)
		printf("%d ",queue[i]);
	printf("\n");
}
