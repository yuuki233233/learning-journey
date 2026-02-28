#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

char* my_tolower_toupper(char* ch)
{
    if (*ch >= 'a' && *ch <= 'z')
    {
        *ch -= 32;
        return ch;
    }
    else if (*ch >= 'A' && *ch <= 'z')
    {
        *ch += 32;
        return ch;
    }
    else
    {
        printf("error");
        *ch = 0;
        return ch;
    }
}

int main()
{
    char ch = 0;
    scanf("%c", &ch);
    char* set = my_tolower_toupper(&ch);

    if (*set >= 'A' && *set <= 'z')
        printf("%c", *set);

    return 0;
}