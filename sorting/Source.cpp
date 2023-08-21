#include<iostream>
#include"stdlib.h"
#include"stdio.h"
using namespace std;

void selection_sort(int arr[],int len);
void bubble_sort(int arr[],int len);
void insert_sort(int arr[], int len);
void heap_sort(int arr[],int len);
void heap_convert(int out[], int len);
void quick_sort(int arr[],int head,int tail);
void printList(int arr[], int len);
void merge_sort(int arr[],int len);
int main()
{
	int list[] = { 8,  7,  5,  6,  4,  2,  3,  1, 18,
				  17, 15, 16, 14, 12, 13, 11, 9, 10 };
	int list2[] = { 75,23,98,44,57,12,29,64,1001,38,82};

	int len = sizeof(list) / sizeof(list[0]);
	int len2 = sizeof(list2) / sizeof(list2[0]);

	cout<<"list:\n";
	printList(list,len);
	cout << "sort list:\n";
	//quick_sort(list,0,len-1);
	//heap_sort(list,len);
	//selection_sort(list,len);
	//bubble_sort(list, len);
	//insert_sort(list, len);
	merge_sort(list,len);
	printList(list,len);

	cout<<"\nlist2:\n";
	printList(list2,len2);
	cout << "sort list2:\n";
	//quick_sort(list2,0,len2-1);
	//heap_sort(list2,len2);
	//selection_sort(list2,len2);
	//bubble_sort(list2, len2);
	//insert_sort(list2, len2);
	merge_sort(list2,len2);
	printList(list2,len2);
	return 0;
}
void quick_sort(int arr[],int head,int tail)
{
	int i = head + 1;
	int j = tail;
	if (head < tail)
	{
		int temp;

		while (i<tail && arr[head] > arr[i])
			i++;
		while (j>head && arr[head] <= arr[j])
			j--;

		while (i<j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j]=temp;
			i++;
			j--;
			while (i<tail && arr[head] > arr[i])
				i++;
			while (j >head &&  arr[head] <= arr[j])
				j--;
		}
		temp = arr[head];
		arr[head] = arr[j];
		arr[j] = temp;
		quick_sort(arr,head,j-1);
		quick_sort(arr,j + 1,tail);
	}
}
void bubble_sort(int arr[], int len)
{
	for (int i = 1; i <=len; i++)
	{
		for (int j =1;j<len;j++)
		{
			if (arr[j-1] > arr[j])
			{
				int temp=arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void insert_sort(int arr[], int len)
{
	for (int i = 1; i < len; i++)
	{
		int index = i,val=arr[index];
		while(index>0&&val < arr[index - 1])
		{
			arr[index] = arr[index - 1];
			index--;
		}
		arr[index] = val;
	}
}
void heap_sort(int arr[], int len)
{
	int* out = (int*)malloc(sizeof(int) * len + 1);
	for (int i = 0; i < len; i++)
		out[i+1] = arr[i];
	heap_convert(out, len);

	for (int i = len; i >0; i--)
	{
		int temp=out[i];
		out[i]=out[1];
		out[1] = temp;
		heap_convert(out,i-1);
	}

	for (int i = 1; i <=len; i++)
		arr[i - 1] = out[i];
}
void heap_convert(int out[], int len)
{
	int start_index;
	int start_value;

	for (int i = len / 2; i > 0; i--)
	{
		start_index = i;
		start_value = out[start_index];
		start_index = start_index * 2;

		while (start_index <= len)
		{
			int next_lv = out[start_index];
			if (start_index < len)
			{
				if (out[start_index] < out[start_index + 1])
				{
					next_lv = out[start_index + 1];
					start_index += 1;
				}
			}
			if (start_value < next_lv)
			{
				out[start_index / 2] = next_lv;
				start_index *= 2;
			}
			else
				break;
		}
		out[start_index / 2] = start_value;
	}
}

void selection_sort(int arr[],int len)
{
	int min,index,temp;
	for (int i = 0; i < len; i++)
	{
		index = i;
		min = arr[i];
		for (int j = i+1; j < len; j++)
		{
			if (min > arr[j])
			{
				index = j;
				min = arr[j];
			}
		}
		temp = arr[i];
		arr[i] = min;
		arr[index] = temp;
	}
}
void merge_sort(int arr[], int len)
{
	if (len < 4)
	{
		selection_sort(arr,len);
		return;
	}
	int mid = len / 2;
	merge_sort(arr,mid);
	merge_sort(arr+mid,len-mid);
	
	int *ans=(int*)malloc(sizeof(int)*len);

	int t1_index = 0;
	int t2_index=mid;
	int i = 0;

	while(t1_index<mid && t2_index<len)
	{
		if (arr[t1_index] <= arr[t2_index])
		{
			ans[i] = arr[t1_index];;
			t1_index++;
		}
		else
		{
			ans[i] = arr[t2_index];
			t2_index++;
		}
		i++;
	}

	while (t1_index < mid)
	{
		ans[i] = arr[t1_index];
		t1_index++;
		i++;
	}
	while (t2_index <len)
	{
		ans[i] = arr[t2_index];
		t2_index++;
		i++;
	}

	for (i = 0; i < len; i++)
		arr[i] = ans[i];
	free(ans);
}
void printList(int arr[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++) 
		cout<<arr[i]<<" ";
	printf("\n");
}