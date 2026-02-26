#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//域
namespace yuuki
{
	// 命名空间中可以定义变量/函数/类型
	int rand = 10;	//常量

	//函数
	int Add(int left, int right)
	{
		return left + right;
	}

	//结构体
	struct Node
	{
		struct Node* next;
		int val;
	};

}//注意：没有分号

int main()
{
	// 这里默认是访问的是全局的rand函数指针
	printf("rand = %p\n", rand);
	// 这里指定bit命名空间中的rand
	printf("yuuki::rand = %d\n", yuuki::rand);

	printf("yuuki::Add = %p\n", yuuki::Add);
	printf("yuuki::Add(1, 2) = %d\n", yuuki::Add(1, 2));

	struct yuuki::Node node;

	return 0;
}