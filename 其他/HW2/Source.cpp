#include<stdlib.h>
#include<stdio.h>
#include"tset.h"

int main()
{
	cout << "case 1.\n";
	TSet A, B, C;
	char CC = 'h';
	A=TSet("abcdef");
	B=TSet("chfeechi");
	cout <<"A:{"<<A<<"}\n";
	cout <<"B:{"<<B<<"}\n";
	C = A + B;
	cout << "A + B:{"<<C<<"}\n";
	C = A * B;
	cout << "A * B:{" << C << "}\n";
	C = A - B;
	cout << "A - B:{" << C << "}\n";
	C = B - A;
	cout << "B - A:{" << C << "}\n";

	if (A>=B == true)
		cout << "A contains B\n";
	else
		cout << "A dose not contain B\n";
	if (B>=A == true)
		cout << "B contains A\n";
	else
		cout << "B dose not contain A\n";

	if (A.in(CC) == true)
		cout << CC<<" is in A\n";
	else
		cout << CC << " is not in A\n";
	if (B.in(CC) == true)
		cout << CC << " is in B\n";
	else
		cout << CC << " is not in B\n";

	cout << "\ncase 2.\n";
	A = TSet("3abf4ec");
	B = TSet("43");
	CC = 'g';
	cout << "A:{" << A << "}\n";
	cout << "B:{" << B << "}\n";
	C = A + B;
	cout << "A + B:{" << C << "}\n";
	C = A * B;
	cout << "A * B:{" << C << "}\n";
	C = A - B;
	cout << "A - B:{" << C << "}\n";
	C = B - A;
	cout << "B - A:{" << C << "}\n";

	if (A >= B == true)
		cout << "A contains B\n";
	else
		cout << "A dose not contain B\n";
	if (B >= A == true)
		cout << "B contains A\n";
	else
		cout << "B dose not contain A\n";

	if (A.in(CC) == true)
		cout << CC << " is in A\n";
	else
		cout << CC << " is not in A\n";
	if (B.in(CC) == true)
		cout << CC << " is in B\n";
	else
		cout << CC << " is not in B\n";

	return 0;
}
