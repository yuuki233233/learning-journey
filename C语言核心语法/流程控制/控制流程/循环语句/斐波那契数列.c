#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
    char arr[100] = { 0 };
    scanf("%s", arr);
    size_t len = strlen(arr);

    for (int i = 0; i < len / 2; i++)
    {
        char a = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = a;
    }
    printf("%s", arr);
    return 0;
}