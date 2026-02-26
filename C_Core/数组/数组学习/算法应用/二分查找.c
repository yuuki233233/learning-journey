#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int k = 7;

	int len = sizeof(arr) / sizeof(arr[0]);
	int flag = 0;

	int left = 0;
	int right = len - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			flag = 1;
			printf("找到了,下标是%d\n", mid);
			break;
		}
	}
	if (flag == 0)
	{
		printf("找不到\n");
	}
	return 0;

}