#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int n = 0;
	printf("请输入个数字(数字越大菱形越大):");
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			printf(" ");
		}
		for (int k = 1; k <= i; k++) {
			printf("%d", k);
		}
		for (int k = i - 1; k > 0; k--) {
			printf("%d", k);
		}
		printf("\n");
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf(" ");
		}
		for (int k = 1; k <= n - i; k++) {
			printf("%d", k);
		}
		for (int k = n - i - 1; k > 0; k--) {
			printf("%d", k);
		}
		printf("\n");
	}
	return 0;
}