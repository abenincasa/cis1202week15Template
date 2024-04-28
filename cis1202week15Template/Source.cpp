/*
Anthony (Tony) Benincasa 4/28/2024 CIS1202.N01
Week 15 Template
This program is to explore the use of templates.
*/

#include "perslib.h"

template <typename T>
T half(T number)
{
	return number / 2.0;
}
int half(int);

int main()
{
	double a = 7.0;
	float b = 5.0f;
	int c = 3;

	cout << half(a) << endl;
	cout << half(b) << endl;
	cout << half(c) << endl;

	endProg();
}
int half(int value) {
	return round(static_cast<float>(value)/2.0);
}