#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int n = 0;
	printf("输入金字塔的层数: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			printf(" ");
		}
		for (int j = 1; j <= i; j++) {
			printf("%d", j);
		}
		for (int k = i - 1; k > 0; k--) {
			printf("%d", k);
		}
		printf("\n");
	}


	return 0;
}