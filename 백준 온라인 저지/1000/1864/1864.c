// 1864번 : 문어

#include <stdio.h>
#include <string.h>
#include <math.h>
#define size 9

char arr[size];

int main()
{
    while (scanf("%s", arr) != '#')
    {
        if (arr[0] == '#')
        {
            break;
        }
        int length = strlen(arr);
        int i = 0, result = 0, expo;
        while (length != 0)
        {
            char str = arr[i];
            switch (str)
            {
            case '-':
                expo = 0;
                break;
            case '\\':
                expo = 1;
                break;
            case '(':
                expo = 2;
                break;
            case '@':
                expo = 3;
                break;
            case '?':
                expo = 4;
                break;
            case '>':
                expo = 5;
                break;
            case '&':
                expo = 6;
                break;
            case '%':
                expo = 7;
                break;
            case '/':
                expo = -1;
                break;
            }
            result += expo * pow(8, length - 1);
            length--;
            i++;
        }
        printf("%d\n", result);
    }
    return 0;
}