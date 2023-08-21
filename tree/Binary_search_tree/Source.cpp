#include<iostream>
#include<string>
#include"stdlib.h"
#include"stdio.h"

using namespace std;

struct person
{
	char Name[20];
	int Score;
};
struct tree
{
	struct person D;
	struct tree* L, * R;
};
void insert(struct tree** r,struct person* data);
void remove(struct tree** r, struct person* data);
void preorder(struct tree* r);
int main()
{	struct tree *root;
	root = NULL;

	struct person data[] =
	{
		{"aka", 92}, {"bba", 100},   {"cc",43},    {"biu", 56},
		{"kk", 85},   {"mm", 61},   {"nb", 55}, {"may",76},
		{"haha", 97},   {"pp", 61}, {"rr", 60},    {"gg", 62},
		{"ahhh", 13},
	};
	int data_size = sizeof(data) / sizeof(data[0]);
	
	for (int i = 0; i < data_size; i++)
		insert(&root,&data[i]);

	cout << endl;
	preorder(root);
	cout << endl;

	struct person extra = {"bbk",99};
	struct person extra_2 = { "XD",3};

	remove(&root, &data[0]);
	preorder(root);
	cout << endl;

	remove(&root, &data[3]);
	preorder(root);
	cout << endl;

	remove(&root, &data[5]);
	preorder(root);
	cout << endl;

	remove(&root, &data[8]);
	preorder(root);
	cout << endl;


	insert(&root, &extra);
	insert(&root, &extra_2);
	preorder(root);
	cout << endl;


	return 0;
}
void insert(struct tree** r, struct person* data)
{
	struct tree* temp;
	temp = (struct tree*)malloc(sizeof(struct tree));
	if (*r == NULL)
	{
		memcpy(temp->D.Name,data->Name,20);
		temp->D.Score=data->Score;
		temp->L = NULL;
		temp->R = NULL;
		*r = temp;
	}
	else
	{
		memcpy(temp->D.Name,data->Name,20);
		temp->D.Score = data->Score;
		temp->L = NULL;
		temp->R = NULL;
		struct tree* current = *r;
		struct tree *prev=current;

		while(current!=NULL)
		{
			prev = current;
			if (current->D.Score <= data->Score)
				current = current->L;
			else
				current = current->R;
		}
		if (prev->D.Score <= data->Score)
			prev->L = temp;
		else
			prev->R = temp;
	}
	cout << "Student " << data->Name << "(" << data->Score << ")'s data inserted\n";
}
void remove(struct tree** r,struct person* data)
{
	if (*r == NULL)
		cout << "Tree no element\n";
	else
	{
		struct tree* current,*prev;
		current = *r; 
		prev = current;
		while (current != NULL && strcmp(current->D.Name,data->Name) != 0)
		{
			prev = current;
			if (current->D.Score < data->Score)
				current = current->L;
			else
				current = current->R;
		}
		if (current == NULL)
		{
			cout << "No this student\n";
			return;
		}

		cout << "Student " << data->Name <<"(" <<data->Score<< ")'s data deleted\n";

		if (current->L == NULL && current->R == NULL)
		{
			if (current==*r)
				*r = NULL;
			else
			{
				if (current->D.Score <= prev->D.Score)
					prev->L = NULL;
				else
					prev->R = NULL;
			}
		}
		else if (current->L != NULL)
		{
			struct tree* replace=current->L;
			struct tree* replace_parent = current;
			while (replace->R != NULL)
			{
				replace_parent = replace;
				replace = replace->R;
			}
			memcpy(current->D.Name,replace->D.Name,20);
			current->D.Score=replace->D.Score;
			if (replace_parent == current)
				replace_parent->L = replace->L;
			else
				replace_parent->R = replace->L;
		}
		else if (current->R != NULL)
		{
			struct tree* replace = current->R;
			struct tree* replace_parent = current;
			while (replace->L != NULL)
			{
				replace_parent = replace;
				replace = replace->L;
			}
			memcpy(current->D.Name, replace->D.Name, 20);
			current->D.Score = replace->D.Score;

			if (replace_parent == current)
				replace_parent->R = replace->R;
			else
				replace_parent->L = replace->R;
		}
	}
}
void preorder(struct tree *r)
{
	if (r != NULL)
	{
		preorder(r->L);
		cout << "Student Name(Score):" << r->D.Name << "(" << r->D.Score<<")"<< endl;
		preorder(r->R);
	}
}
