#include<stdlib.h>
#include<stdio.h>
void radix_sort(int arr[],int len);
int main()
{
	int list[] = { 8,  7,  5,  6,  4,  2,  3,  1 , 18 ,
				  17, 15, 16, 14, 12, 13, 11, 9, 10 };
	int list2[] = {75,23,98,44,57,12,29,64,1001,38,82};
	int len = sizeof(list) / sizeof(list[0]);
	int len2 = sizeof(list2) / sizeof(list2[0]);


	printf("list(before):\n");
	for (int i = 0; i < len; i++)
		printf("%d ", list[i]);
	printf("\n");

	radix_sort(list,len);
	printf("list(after):\n");
	for (int i = 0; i < len; i++)
		printf("%d ", list[i]);
	printf("\n\n");

	printf("list2(before):\n");
	for (int i = 0; i < len2; i++)
		printf("%d ", list2[i]);
	printf("\n");

	radix_sort(list2, len2);

	printf("list2(after):\n");
	for (int i = 0; i < len2; i++)
		printf("%d ", list2[i]);
	printf("\n\n");

	return 0;
}
void radix_sort(int arr[], int len)
{
	struct data
	{
		int n;
		struct data* next;
	};
	struct data *container[10];
	for(int i=0;i<10;i++)
		container[i]=NULL;
	
	int max=0;
	for (int i = 0; i < len; i++)
	{
		if (max <= arr[i])
			max = arr[i];
	}

	int power=1,p=0;
	while (max / power != 0)
	{
		power *= 10;
		p++;
	}
	power = 1;
	int temp;
	for (int r = 0; r <p; r++)
	{
		for (int i = 0; i < len; i++)
		{
			temp = arr[i] / power;
			struct data* ptr = (struct data*)malloc(sizeof(struct data));
			if (container[temp % 10] == NULL)
			{
				ptr->n = arr[i];
				ptr->next = NULL;
				container[temp % 10] = ptr;
			}
			else
			{
				ptr->n = arr[i];
				ptr->next = NULL;
				struct data* current = container[temp%10];
				while (current->next != NULL)
					current = current->next;
				current->next = ptr;
			}
		}
		int index=0;
		for (int i = 0; i < 10; i++)
		{
			struct data* current = container[i];
			while(current != NULL)
			{
				arr[index] = current->n;
				current = current->next;
				index++;
			}
			container[i] = NULL;
		}	
		power *= 10;
	}
}