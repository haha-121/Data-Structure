#pragma once
#include<iostream>
using namespace std;
class TSet
{
private:
	char table[256];
	int LEN;
public:
	TSet();
	TSet(const char* s);
	~TSet() {};
	TSet operator+(const TSet &obj);
	TSet operator-(const TSet& obj);
	TSet operator*(const TSet& obj);
	bool operator>=(const TSet& obj);
	bool in(const char c);
	friend ostream &operator<<(ostream &os,const TSet&obj);
};
