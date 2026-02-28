#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct Student
{
    char name[20];
    int age;
    int high;
    float weight;
    int id[16];
}s4, s5, s6;
//s4, s5, s6是结构体全局变量

int main()
{
    struct Student s1 = { "张三", 20, 180, 75.5f, 1234567890 };//初始化
    struct Student s2 = { .age = 30, .name = "李四", .weight = 80.5f, .high = 177,  .id = 1234567891 };//不按顺序排的,前面要加.
    printf("%s %d %d %.1f %d\n", s1.name, s1.age, s1.high, s1.weight, s1.id);
        //struck Student s3;
        //s1, s2, s3是结构体的局部变量
        return 0;
}