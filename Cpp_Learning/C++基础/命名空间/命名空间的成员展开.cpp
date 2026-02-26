#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
namespace N
{
	int a = 10;
	int b = 20;
}

#if 0
// using将命名空间中某个成员展开
using N::b;
int main()
{
	printf("%d\n", N::a); //10
	printf("%d\n", b); //20
	return 0;
}
#endif

// 展开命名空间中全部成员
using namespace N;
int main()
{
	printf("%d\n", a); //10
	printf("%d\n", b); //20
	return 0;
}
