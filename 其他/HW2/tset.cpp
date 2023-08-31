#include"tset.h"

TSet::TSet()
{
	for (int i = 0; i < 256; i++)
		table[i] = '\0';
	LEN = 0;
}
TSet::TSet(const char* s)
{
	for (int i = 0; i < 256; i++)
		table[i] = '\0';
	LEN = 0;

	int min=256;
	while (*s != '\0')
	{
		if (table[(int)*s] == '\0')
		{
			table[(int)*s] = *s;
			LEN++;
			if (min > (int)*s)
				min = (int)*s;
		}
		s++;
	}

	int start = 0;
	for (int i = min; i < 256; i++)
	{
		if (table[i] != '\0')
		{
			table[start] = table[i];
			start++;
		}
	}
	for (int i =start; i < 256; i++)
		table[i] = '\0';
}
TSet TSet::operator+(const TSet& obj)
{
	TSet out=TSet();

	for (int i = 0; i <LEN; i++)
	{
		out.table[(int)table[i]] = table[i];
		out.LEN++;
	}
	for (int i = 0; i < obj.LEN; i++)
	{
		if (out.table[(int)(obj.table[i])] == '\0')
		{
			out.table[(int)(obj.table[i])] = obj.table[i];
			out.LEN++;
		}
	}

	int start = 0;
	for (int i = 0; i < 256; i++)
	{
		if (out.table[i] != '\0')
		{
			out.table[start] = out.table[i];
			start++;
		}
	}
	for (int i = start; i < 256; i++)
		out.table[i] = '\0';

	return out;
}
TSet TSet::operator-(const TSet& obj)
{	
	TSet Intersection = *this*obj;
	TSet out = TSet();
	int start = 0;
	for (int i = 0; i < LEN; i++)
	{
		int j = 0;
		for (j = 0; j < Intersection.LEN; j++)
		{
			if (table[i] == Intersection.table[j])
				break;
		}
		if (j == Intersection.LEN)
		{
			out.table[start] = table[i];
			out.LEN++;
			start++;
		}
	}
	return out;
}
TSet TSet::operator*(const TSet& obj)
{
	TSet out = TSet();
	int start = 0;
	for (int i = 0; i < obj.LEN; i++)
	{
		for (int j = 0; j < LEN; j++)
		{
			if (obj.table[i] == table[j])
			{
				out.table[start] = table[j];
				out.LEN++;
				start++;
				break;
			}
		}
	}
	return out;
}
ostream& operator<<(ostream& os, const TSet& obj)
{
	for (int i = 0; i < obj.LEN; i++)
		os << obj.table[i];
	return os;
}
bool TSet::operator>=(const TSet& obj)
{
	TSet Intersection = *this * obj;
	if (Intersection.LEN != obj.LEN)
		return false;
	for (int i = 0; i < obj.LEN; i++)
	{
		if (Intersection.table[i] != obj.table[i])
			return false;
	}
	return true;
}
bool TSet::in(const char c)
{
	for (int i = 0; i < LEN; i++)
	{
		if (c ==table[i])
			return true;
	}
	return false;
}