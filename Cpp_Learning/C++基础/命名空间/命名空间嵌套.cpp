#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

namespace yuuki
{
	namespace A
	{
		int rand = 10;
		int Add(int x, int y)
		{
			return x + y;
		}
	}

	namespace B
	{
		int rand = 20;
		int Sub(int x, int y)
		{
			return x - y;
		}
	}
}

int main()
{
	printf("yuuki->A->rand = %d\n", yuuki::A::rand);
	printf("yuuki->B->rand = %d\n", yuuki::B::rand);

	printf("yuuki->A->Add = %d\n", yuuki::A::Add(1, 1));
	printf("yuuki->B->Sub = %d\n", yuuki::B::Sub(1, 1));

	return 0;
}