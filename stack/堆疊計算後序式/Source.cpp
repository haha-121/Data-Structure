#include<stdlib.h>
#include<stdio.h>

enum p {plus,minus,times,divide,mod,eos,operand};
typedef enum p precedence;

precedence getToken(char* expr,char *s,int *n);
int eval(char*c);

int level = -1;
int stack[100];
void push(int n);
int pop();
int main()
{
	char equationa1[] = "62/3-42*+";//6/2-3+4*2
	printf("%d\n",eval(equationa1));
	
	char equationa2[] = "59*8+";//5*9+8
	printf("%d\n", eval(equationa2));

	char equationa3[] = "62+4+";//6+2+4
	printf("%d\n", eval(equationa3));
	return 0;
}
int eval(char *c)
{
	precedence token;
	int op1, op2;
	int n = 0;
	char symbol;
	token = getToken(c,&symbol,&n);
	while (token != eos)
	{
		if (token == operand)
			push(symbol-'0');
		else
		{
			op2 = pop();
			op1 = pop();
			switch (token)
			{
				case plus:
					push(op1+op2);
					break;
				case minus:
					push(op1 - op2);
					break;
				case times:
					push(op1*op2);
					break;
				case divide:
					push(op1 / op2);
					break;
				case mod:
					push(op1 % op2);
					break;
			}
		}
		token = getToken(c,&symbol,&n);
	}
	return pop();
}
precedence getToken(char* expr,char *s,int *n)
{
	*s = expr[(*n)++];
	switch (*s)
	{
		case '+':
			return plus;
		case '-':
			return minus;
		case '*':
			return times;
		case '/':
			return divide;
		case '%':
			return mod;
		case '\0':
			return eos;
		default:
			return operand;
	}
}
void push(int n)
{
	stack[++level] = n;
}
int pop()
{
	return stack[level--];
}
