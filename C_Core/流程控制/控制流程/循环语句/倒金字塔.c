#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int a = 0;
	printf("请输入倒立金字塔的层数");
	scanf("%d", &a);

	//可以理解外层循环管理纵,内层循环管理横
	for (int i = 0; i < a; i++) {
		for (int j = 1; j <= i; j++) {  //倒立金字塔,从上到下空格增多,所以用(增)
			printf(" ");
		}
		for (int f = 1; f <= a - i; f++) { //管理左边数字,且数字依次减少,所以用(总-增)
			printf("%d", f);
		}
		for (int k = a - i - 1; k > 0; k--) {  //管理右边数字,且数字依次减少呈现4321样,所以用反for与(总-增-1)
			printf("%d", k);
		}
		printf("\n");
	}
	return 0;
}