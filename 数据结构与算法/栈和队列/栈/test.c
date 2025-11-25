#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"

int main()
{
	ST s;
	STInit(&s);
	STPush(&s, 1);
	STPush(&s, 2);
	STPush(&s, 3);
	STPush(&s, 4);

	printf("%d\n", STTop(&s)); //4
	
	while (!STEmpty(&s))
	{
		//取栈顶
		printf("&d ", STTop(&s));
		//删一个元素
		STPop(&s);
	}

	STDestroy(&s);
	return 0;
}