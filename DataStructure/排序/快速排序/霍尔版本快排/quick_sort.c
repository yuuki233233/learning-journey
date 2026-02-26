#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//插入排序
void insertion_sort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			//从小到大排序
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		//将数据插入到空位
		arr[end + 1] = tmp;
	}
}

void Swap(int* x, int* y)
{
	int* tmp = *x;
	*x = *y;
	*y = tmp;
}

//三数取中
int GetMidi(int* arr, int left, int right)
{
	int mid = (right + left) / 2;
	if (arr[mid] < arr[left])
	{
		if (arr[mid] > arr[right])
		{
			return mid;
		}
		else if (arr[left] < arr[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (arr[mid] < arr[right])
		{
			return mid;
		}
		else if (arr[right] < arr[left])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
}

//避免有序情况下，效率退化
//三数取中
void quick_sort(int* arr, int left, int right)
{
	if (left >= right)
		return;

	//小区间优化，不再递归分割排序，减少递归的次数
	if ((right - left + 1) < 10)
	{
		insertion_sort(arr + left, right - left + 1);
	}
	else
	{
		//三数取中
		int midi = GetMidi(arr, left, right);
		Swap(&arr[left], &arr[midi]);

		int keyi = left;
		int begin = left, end = right;
		while (begin < end)
		{
			//左边做key，先让右边先走，再让左边走(可以保持key比停下的位置的元素大)
			//右边做key，先让左边先走，再让右边走(可以保持key比停下的位置的元素小)
			//结论：一边做key，让另一边先走
			while (begin < end && arr[end] >= arr[keyi])
			{
				end--;
			}

			while (begin < end && arr[begin] <= arr[keyi])
			{
				begin++;
			}
			Swap(&arr[begin], &arr[end]);
		}
		Swap(&arr[keyi], &arr[begin]);
		keyi = begin;

		quick_sort(arr, left, keyi - 1);
		quick_sort(arr, keyi + 1, right);
	}
	
}



int main()
{
	int arr[] = { 9,5,7,1,6,3,0,6,5,2 };
	int len = sizeof(arr) / sizeof(arr[0]);

	quick_sort(arr, 0, len - 1);
}