#define _CRT_SECURE_NO_WARNINGS
#include"Date.h"

int main()
{
	Date d1(2025, 11, 28);
	d1.Print();

	Date d2 = d1 + 100;
	d2.Print();

	return 0;
}