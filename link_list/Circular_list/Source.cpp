#include<iostream>

struct node
{
	int n;
	struct node* next;
};
struct node* head, * tail;
void insert(int num);
void Delete(int num);
void display();
int main()
{
	head = NULL;
	tail = NULL;

	printf("inserted 10\n");
	insert(10);
	printf("head:%d\n",head->n);
	printf("tail:%d\n",tail->n);
	printf("head next:%d\n", head->next->n);
	printf("tail next:%d\n", tail->next->n);
	display();

	printf("inserted 20 30 40 50 60\n");
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	insert(60);
	printf("head:%d\n", head->n);
	printf("tail:%d\n", tail->n);
	printf("head next:%d\n", head->next->n);
	printf("tail next:%d\n", tail->next->n);
	display();

	printf("deleted 10\n");
	Delete(10);
	printf("head:%d\n", head->n);
	printf("tail:%d\n", tail->n);
	printf("head next:%d\n", head->next->n);
	printf("tail next:%d\n", tail->next->n);
	display();


	printf("deleted 60\n");
	Delete(60);
	printf("head:%d\n", head->n);
	printf("tail:%d\n", tail->n);
	printf("head next:%d\n", head->next->n);
	printf("tail next:%d\n", tail->next->n);
	display();

	printf("deleted 40\n");
	Delete(40);
	printf("head:%d\n", head->n);
	printf("tail:%d\n", tail->n);
	printf("head next:%d\n", head->next->n);
	printf("tail next:%d\n", tail->next->n);
	display();
	return 0;
}
void insert(int num)
{
	struct node* ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->n = num;
	if (head == NULL&&tail==NULL)
	{
		ptr->next = ptr;
		head =tail=ptr;
	}
	else
	{
		ptr->next = head;
		tail->next = ptr;
		tail = ptr;
	}
}
void Delete(int num)
{
	struct node* current,*prev;
	current = head;
	prev = head;
	if (head == tail)
	{
		if (current->n != num)
			printf("No this data\n");
		else
			head = tail = NULL;
		return;
	}
	while (current->n!=num)
	{
		prev = current;
		current = current->next;
	}
	if (current->n != num)
	{
		printf("No this data\n");
		return;
	}
		
	if (current == head)
	{
		head = current->next;
		tail->next = head;
	}
	else if (current == tail)
	{
		prev->next = current->next;
		tail=prev ;
	}
	else
		prev->next = current->next;
	free(current);
}
void display()
{
	struct node* current;
	current = head;
	printf("%d ", current->n);
	while (current!= tail)
	{
		current = current->next;
		printf("%d ",current->n);
	}

	printf("\n\n");
}