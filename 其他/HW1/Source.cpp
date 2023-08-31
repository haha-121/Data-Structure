#include<stdlib.h>
#include<stdio.h>

//#define SIZE 3

void magic_matrix();
void Factorial();
int main()
{	
	magic_matrix();
	Factorial();
	return 0;
}
void magic_matrix()
{
	int SIZE = 1;
	//int arr[SIZE][SIZE] = { 0 };
	printf("Array size:");
	scanf_s("%d", &SIZE);

	int** arr = new int* [SIZE];
	for (int i = 0; i < SIZE; i++)
		arr[i] = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
		arr[i][j] = 0;

	int x = 0, y = SIZE / 2, val = 2;
	arr[x][y] = 1;

	int memx, memy;
	for (int i = 1; i < SIZE * SIZE; i++)
	{
		memx = x;
		memy = y;
		x = x - 1;
		if (x < 0)
			x = SIZE - 1;
		y = y - 1;
		if (y < 0)
			y = SIZE - 1;

		if (arr[x][y] != 0)
		{
			if (SIZE != 1)
			{
				x = memx + 1;
				y = memy;
				arr[x][y] = val;
			}
		}
		else
			arr[x][y] = val;
		val++;
	}

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			printf("%d\t", arr[i][j]);
		printf("\n\n");
	}

	for (int i = 0; i < SIZE; i++)
		delete[] arr[i];
	delete[] arr;
}
void Factorial()
{
	int data[100] = { 0 };
	int index = 99;
	int n=1;
	printf("Factorial:");
	scanf_s("%d",&n);

	for (int i = 1; i <= n; i++)
	{
		printf("%d!=",i);
		data[index] = 1;
		for (int r = 2; r <= i; r++)
		{
			for (int p = index; p <= 99; p++)
				data[p] *= r;
			
			if (data[index] >= 10)
				index--;

			for (int p = 99; p >index;p--)
			{
				if (data[p] >= 10)
				{
					data[p -1] = data[p - 1] + (data[p] / 10);
					data[p] = data[p] % 10;
				}
			}		
		}

		for (int r = index; r <=99; r++)
			printf("%d",data[r]);
		
		for (int r = 0; r <= 99; r++)
			data[r] = 0;

		index = 99;
		printf("\n");
	}
}