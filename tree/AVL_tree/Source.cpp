#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
struct person
{
	char Name[20];
	int Score;
};
struct tree
{
	int bf;
	struct person D;
	struct tree* L, * R;
};
void insert(struct person* p);
void remove(struct person* p);
void ptrfind(struct tree *r);
void preorder(struct tree* r);
void bfcount(struct tree* r);
int heightcount(struct tree* r);
int typefind();
void pivotfind();
void LL();
void LR();
void RR();
void RL();

using namespace std;
struct tree *root,*pivot,*pivotprev,*temp,*Prev;

int main()
{
	root = NULL;
	pivot = NULL;
	struct person data[] =
	{
		{"aka", 92}, {"bba", 100},   {"cc",43},    {"biu", 56},
		{"kk", 85},   {"mm", 61},   {"nb", 55}, {"may",76},
		{"haha", 97},   {"pp", 61}, {"rr", 60},    {"gg", 62},
		{"ahhh", 13},
	};
	int data_size = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i <data_size; i++)
		insert(&data[i]);

	cout << endl;
	preorder(root);
	cout << endl;

	struct person extra = { "bbk",99 };
	struct person extra_2 = { "XD",3 };

	remove(&data[0]);
	preorder(root);
	cout << endl;

	remove(&data[3]);
	preorder(root);
	cout << endl;

	remove(&data[5]);
	preorder(root);
	cout << endl;

	remove(&data[8]);
	preorder(root);
	cout << endl;

	insert(&extra);
	insert(&extra_2);
	preorder(root);
	cout << endl;

	return 0;
}
void insert(struct person* p)
{
	temp = (struct tree*)malloc(sizeof(struct tree));
	if (root == NULL)
	{
		temp->L = NULL;
		temp->R = NULL;
		temp->D.Score=p->Score;
		memcpy(temp->D.Name, p->Name,20);
		root = temp;
	}
	else
	{
		temp->L = NULL;
		temp->R = NULL;
		temp->D.Score = p->Score;
		memcpy(temp->D.Name, p->Name, 20);

		struct tree* current;
		current = root;
		Prev = current;
		while (current != NULL)
		{
			Prev = current;
			if (current->D.Score >= p->Score)
				current = current->L;
			else
				current = current->R;
		}
		if (Prev->D.Score >= p->Score)
			Prev->L = temp;
		else
			Prev->R = temp;
	}
	bfcount(root);
	pivotfind();
	if (pivot != NULL)
	{
		int op = typefind();
		switch (op)
		{
			case 11:
				LL();
				break;
			case 12:
				LR();
				break;
			case 21:
				RL(); 
				break;
			case 22:
				RR();
				break;
		}
		bfcount(root);
	}
}
void remove(struct person* p)
{
	if (root == NULL)
		cout << "Tree no element\n";
	else
	{
		struct tree* current;
		current = root;
		Prev = current;
		while (current != NULL && strcmp(current->D.Name,p->Name) != 0)
		{
			Prev = current;
			if (current->D.Score >= p->Score)
				current = current->L;
			else
				current = current->R;
		}
		if (current == NULL)
		{
			cout << "No this student\n";
			return;
		}
		cout << "Student " << p->Name << "(" << p->Score << ")'s data deleted\n";

		if (current->L == NULL && current->R == NULL)
		{
			if (current == root)
				root = NULL;
			else
			{
				if (current->D.Score >= Prev->D.Score)
					Prev->R = NULL;
				else
					Prev->L = NULL;
				ptrfind(Prev);
			}
		}
		else if (current->L != NULL)
		{
			struct tree* replace=current->L;
			struct tree* replace_p = current;
			while (replace->R != NULL)
			{
				replace_p = replace;
				replace = replace->R;
			}

			if (replace_p->D.Score<replace->D.Score)
				replace_p->R = replace->L;
			else
				replace_p->L = replace->L;

			current->D.Score = replace->D.Score;
			memcpy(current->D.Name,replace->D.Name,20);
		
			ptrfind(Prev);
		}
		else if (current->R != NULL)
		{
			struct tree* replace = current->R;
			struct tree* replace_p = current;
			while (replace->L != NULL)
			{
				replace_p = replace;
				replace = replace->L;
			}

			if (replace_p->D.Score < replace->D.Score)
				replace_p->R = replace->R;
			else
				replace_p->L = replace->R;

			current->D.Score = replace->D.Score;
			memcpy(current->D.Name, replace->D.Name, 20);
			ptrfind(Prev);
		}

		bfcount(root);
		if (root != NULL)
		{
			pivotfind();
			if (pivot != NULL)
			{
				int op = typefind();
				cout << op << "++++" << endl;
				switch (op)
				{
				case 11:
					LL();
					break;
				case 12:
					LR();
					break;
				case 21:
					RL();
					break;
				case 22:
					RR();
					break;
				}
				bfcount(root);
			}
		}

	}
}
void ptrfind(struct tree* p)
{
	struct tree* ltemp, * rtemp;
	ltemp=p;
	rtemp=p;
	int lcount = 0, rcount = 0;
	while (ltemp->L != NULL || ltemp->R != NULL)
	{
		while (ltemp->L!=NULL)
		{
			ltemp = ltemp->L;
			lcount++;
		}
		while (ltemp->R != NULL)
		{
			ltemp = ltemp->R;
			lcount++;
		}
	}

	while (rtemp->R != NULL || rtemp->L != NULL)
	{

		while (rtemp->R != NULL)
		{
			rtemp = rtemp->R;
			rcount++;
		}
		while (rtemp->L != NULL)
		{
			rtemp = rtemp->L;
			rcount++;
		}
	}

	if (lcount >= rcount)
		temp = ltemp;
	else
		temp = rtemp;
}


void bfcount(struct tree* r)
{
	if (r != NULL)
	{
		bfcount(r->L);
		bfcount(r->R);
		r->bf = heightcount(r->L)- heightcount(r->R);
	}
}
int heightcount(struct tree* r)
{
	if (r == NULL)
		return 0;
	else if (r->L == NULL && r->R == NULL)
		return 1;
	else
	{
		int l_val = heightcount(r->L);
		int r_val = heightcount(r->R);

		if (l_val >= r_val)
			return 1 + l_val;
		else
			return 1 + r_val;
	}
}
void preorder(struct tree* r)
{
	if (r != NULL)
	{
		preorder(r->L);
		cout << "Student Name(Score):" << r->D.Name << "(" << r->D.Score << ") bf:"<<r->bf<< endl;
		preorder(r->R);
	}
}
void pivotfind()
{
	struct tree *current;
	current = root;
	pivot = NULL;
	while (current != temp)
	{
		if (current->bf<-1 || current->bf > 1)
		{
			pivot = current;
			if (pivot != root)
				pivotprev = Prev;
		}
		
		if (current->D.Score >= temp->D.Score)
		{
			Prev = current;
			current = current->L;
		}	
		else
		{
			Prev = current;
			current = current->R;
		}
	}
}
int typefind()
{
	int op = 0;
	struct tree* current;
	current = pivot;
	for(int i=0;i<2;i++)
	{
		if (current->D.Score >= temp->D.Score)
		{
			current = current->L;
			if (op == 0)
				op += 10;
			else
				op++;
		}
		else
		{
			current = current->R;
			if (op == 0)
				op += 20;
			else
				op+=2;
		}
	}
	return op;
}
void LL()
{
	struct tree* pivotNext,*mem;
	pivotNext = pivot->L;
	mem = pivotNext->R;
	pivotNext->R = pivot;
	pivot->L = mem;
	if (pivot == root)
		root = pivotNext;
	else
	{
		if (pivotprev->L == pivot)
			pivotprev->L = pivotNext;
		else
			pivotprev->R = pivotNext;
	}
}
void LR()
{
	struct tree* pivotNext, * mem;
	pivotNext = pivot->L;
	mem = pivotNext->R;
	pivot->L = mem->R;
	pivotNext->R = mem->L;
	mem->L = pivotNext;
	mem->R = pivot;
	if (pivot == root)
		root = mem;
	else
	{
		if (pivotprev->L == pivot)
			pivotprev->L = mem;
		else
			pivotprev->R = mem;
	}
}
void RR()
{
	struct tree* pivotNext, * mem;
	pivotNext = pivot->R;
	mem = pivotNext->L;
	pivotNext->L = pivot;
	pivot->R = mem;
	if (pivot == root)
		root = pivotNext;
	else
	{
		if (pivotprev->L == pivot)
			pivotprev->L = pivotNext;
		else
			pivotprev->R = pivotNext;
	}
}
void RL()
{
	struct tree* pivotNext, * mem;
	pivotNext = pivot->R;
	mem = pivotNext->L;
	pivot->R = mem->L;
	pivotNext->L = mem->R;
	mem->L = pivot;
	mem->R = pivotNext;
	if (pivot == root)
		root = mem;
	else
	{
		if (pivotprev->L == pivot)
			pivotprev->L = mem;
		else
			pivotprev->R = mem;
	}
}