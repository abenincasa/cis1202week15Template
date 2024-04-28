/*
Anthony (Tony) Benincasa 4/28/2024 CIS1202.N01
Week 15 Template
This program is 
*/

#include "perslib.h"

template <typename T>
T half(T number)
{
	return number / 2;
}

int main()
{

	double a = 7.0;
	float b = 5.0f;
	int c = 3;
	// double roundX = round(x);

	cout << half(a) << endl;
	cout << half(b) << endl;
	cout << half(c) << endl;

	endProg();
}
