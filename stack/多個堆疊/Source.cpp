#include<stdlib.h>
#include<stdio.h>

#define MAX 10
#define UINT 2
int stack[MAX];

void push(int user_n);
void pop(int user_n);
void list(int user_n);

int t[UINT+1],b[UINT+1];

int main()
{
	for (int i = 0; i <= UINT; i++)
	{
		t[i] = ((MAX/UINT) * i) - 1;
		b[i] = ((MAX/UINT) * i) - 1;
	}
	int option;
	while (1)
	{
		printf("1.Push data\n");
		printf("2.Pop data\n");
		printf("3.list data\n");
		printf("4.Quit\n");
		printf("Enter choice:");
		scanf_s("%d",&option);
		switch (option)
		{
			int num;
			case 1:
				printf("\nThe total number of stack is %d\n",UINT);
				printf("Choose stack want push:");
				scanf_s("%d",&num);
				if (num > UINT)
					printf("Out of stack total number\n");
				else
					push(num);
				break;
			case 2:
				printf("Choose stack want pop:");
				scanf_s("%d",&num);
				if (num > UINT)
					printf("Out of stack total number\n");
				else
					pop(num);
				break;
			case 3:
				printf("Choose stack want list:");
				scanf_s("%d",&num);
				if (num > UINT)
					printf("Out of stack total number\n");
				else
				list(num);
				break;
			case 4:
				return 0;
			default:
				printf("Error input\n");
		}
	}
	return 0;
}

void push(int user_n)
{
	if (b[user_n-1]>=t[user_n])
		printf("Stack %d now full\n", user_n);
	else
	{
		int d;
		printf("Insert data in stack %d:",user_n);
		scanf_s("%d",&d);
		stack[++t[user_n-1]] = d;
		printf("Data %d insert in stack %d\n\n",d,user_n);
	}
}
void pop(int user_n)
{
	if (b[user_n - 1] == t[user_n-1])
		printf("Stack %d now empty\n", user_n);
	else
		printf("Data %d remove from stack %d\n\n",stack[t[user_n - 1]--], user_n);
}
void list(int user_n)
{
	if(t[user_n - 1]==b[user_n - 1])
		printf("Stack %d now empty\n",user_n);
	else
	{
		printf("Stack %d data:\n",user_n);
		for (int i = b[user_n-1]+1; i <=t[user_n-1];i++)
			printf("%d ",stack[i]);
		printf("\n\n");
	}
}