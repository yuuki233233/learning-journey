#define _CRT_SECURE_NO_WARNINGS
#include"heap.h"

//堆的初始化
void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}

//用指针来交换地址
void swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}

//向上排序
void AdjustUP(HPDataType* a, int child)
{
	//父亲节点
	int ancestor = (child - 1) / 2;

	//条件：当孩子到达首元素停止循环
	while (child > 0)
	{
		//孩子比父亲小，则向上排序(小堆)
		if (a[child] < a[ancestor])
		{
			//条件满足，交换位置
			swap(&(a[ancestor]), &(a[child]));
			//新的一轮
			child = ancestor;
			ancestor = (child - 1) / 2;
		}
		else//不满足条件，跳出while循环
		{
			break;
		}
	}
}

//尾插数据
void HPPush(HP* php, HPDataType x)
{
	assert(php);

	//判断空间是否足够
	if (php->capacity == php->size)
	{
		//三目运算符：
		//1. 当无空间时，申请4个字节
		//2. 当有空间时，将空间乘2倍
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newcapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!!!");
			return;
		}
		//赋值新变量
		php->a = tmp;
		php->capacity = newcapacity;
	}
	//尾插数据，长度+1
	php->a[php->size] = x;
	php->size++;

	//尾插完，排序(大堆/小堆)
	AdjustUP(php->a, php->size - 1);
}

//向下排序
void AdjustDown(HPDataType* a, int n, int ancestor)
{
	//保持紧密的父子关系
	int child = ancestor * 2 + 1;

	//当孩子比总节点大时，停止循环
	while (child < n)
	{
		//两兄弟之间比较(谁大谁小)
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}

		//兄弟与父亲比较，兄弟小则交换
		if (a[child] < a[ancestor])
		{
			swap(&(a[child]), &(a[ancestor]));
			ancestor = child;
			child = ancestor * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//尾删(先首尾交换，避免打乱堆)
void HPPop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	//首尾交换
	swap(&php->a[0], &php->a[php->size - 1]);
	//总大小-1
	php->size--;

	//向下排序
	AdjustDown(php->a, php->size, 0);
}

//首元素查询
HPDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

//判空
bool HPEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}

//堆的删除
void HPDestory(HP* php)
{
	assert(php);

	free(php->a);
	php->a = NULL;

	php->size = php->capacity = 0;
	php = NULL;
}

//TOP-K问题
void CreateNDate()
{
	// 造数据
	 int n = 100000;
	 srand(time(0));
	 const char* file = "data.txt";
	 FILE * fin = fopen(file, "w");
	 if (fin == NULL)
		 {
			perror("fopen error");
			return;
		 }
	
	for (int i = 0; i < n; ++i)
	{
		int x = (rand() + i) % 1000000;
		fprintf(fin, "%d\n", x);
	}
	
	fclose(fin);
	
}

 void topk()
 {
	printf("请输⼊k：>");
	int k = 0;
	scanf("%d", &k);
	
	const char* file = "data.txt";
	FILE * fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}
	
	int val = 0;
	int* minheap = (int*)malloc(sizeof(int) * k);
	if (minheap == NULL)
	{
		perror("malloc error");
		return;
	}
	
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minheap[i]);
	}
	
	// 建k个数据的小堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minheap, k, i);
	}
	
	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
	// 读取剩余数据，比堆顶的值大，就替换他进堆
		if (x > minheap[0])
		{
			minheap[0] = x;
			AdjustDown(minheap, k, 0);
		}
	}
	
	for (int i = 0; i < k; i++)
	{
		printf("%d ", minheap[i]);
	}
	
	fclose(fout);
}