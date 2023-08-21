#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
struct link
{
	int n;
	struct link* next;
};
void Insert(struct link** L,int num);
void Delete(struct link** L,const int target);
void Display(struct link *L);
void Reverse(struct link** L);
int main()
{
	struct link* root=NULL;
	Insert(&root,8);
	Insert(&root,5);
	Insert(&root,9);
	Insert(&root,1);
	Insert(&root,4);
	Insert(&root,3);
	Insert(&root,6);
	Insert(&root, 100);
	Insert(&root, 200);
	Insert(&root, 500);
	Insert(&root, 700);
	Display(root);


	cout << "\n\nReverse link list:\n";
	Reverse(&root);
	Display(root);

	cout << "\n\nRemove data 2:\n";
	Delete(&root,2);
	Display(root);

	cout << "\n\nRemove data 700:\n";
	Delete(&root,700);
	Display(root);

	cout << "\n\nRemove data 6:\n";
	Delete(&root,6);
	Display(root);

	cout << "\n\nReverse link list:\n";
	Reverse(&root);
	Display(root);

	cout << "\n\nRemove data 8:\n";
	Delete(&root,8);
	Display(root);

	cout << "\n\nRemove data 500:\n";
	Delete(&root,500);
	Display(root);
	return 0;
}
void Insert(struct link** L, int num)
{
	struct link *temp;
	temp = (struct link*)malloc(sizeof(struct link));

	if (*L == NULL)
	{
		*L = temp;
		temp->n = num;
		temp->next = NULL;
	}
	else
	{
		temp->n = num;
		temp->next = NULL;
		struct link * current;
		current = *L;
		while (current->next != NULL)
			current = current->next;
		current->next = temp;
	}
}
void Delete(struct link** L,const int target)
{
	if (*L == NULL)
		cout << "Now link list is empty,Can't Delete\n" << endl;
	else
	{
		struct link* current,*prev;
		current = *L;
		prev = current;
		while (current!=NULL&&current->n != target)
		{
			prev = current;
			current = current->next;
		}
		if (current == NULL)
		{
			cout << "data " << target << " not found" << endl;
			return;
		}
		if (current == *L)
			*L = current->next;
		else
			prev->next = current->next;
		cout << "data "<<target<<" deleted" << endl;
	}
}
void Reverse(struct link** L)
{
	if (*L == NULL)
	{
		cout << "Now link list is empty\n" << endl;
		return;
	}
	struct link*prev,* current,* Next;
	prev = NULL;
	current = *L;
	Next = *L;
	while (current != NULL)
	{
		Next= current->next;
		current->next=prev;
		prev = current;
		current = Next;
	}
	*L = prev;
	
}
void Display(struct link* L)
{
	if (L == NULL)
		cout << "Now link list is empty\n" << endl;
	else
	{
		struct link* current;
		current=L;
		while (current != NULL)
		{
			cout << current->n << " ";
			current = current->next;
		}
	}
}