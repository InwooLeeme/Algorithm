// 5622번 : 다이얼

#include <stdio.h>
#include <string.h>
#define size 16

char arr[size];

int main()
{
    int result = 0, count = 0;
    scanf("%s", arr);
    int length = strlen(arr);
    for (int i = 0; i < length; i++)
    {
        char str = arr[i];
        switch (str)
        {
        case ' ':
            result += 2;
            break;
        case 'A':
        case 'B':
        case 'C':
            result += 3;
            break;
        case 'D':
        case 'E':
        case 'F':
            result += 4;
            break;
        case 'G':
        case 'H':
        case 'I':
            result += 5;
            break;
        case 'J':
        case 'K':
        case 'L':
            result += 6;
            break;
        case 'M':
        case 'N':
        case 'O':
            result += 7;
            break;
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
            result += 8;
            break;
        case 'T':
        case 'U':
        case 'V':
            result += 9;
            break;
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            result += 10;
            break;
        }
    }
    printf("%d", result);
    return 0;
}