
// 1152번 : 단어의 개수

#include <stdio.h>
#include <string.h>
#define size 1000001

char arr[size];

int main()
{
    scanf("%[^\n]s", arr);
    int length = strlen(arr);
    int count = 0;

    for (int i = 0; i <= length; i++)
    {
        if (arr[i] == ' ')
        {
            count++;
        }
    }
    if (arr[0] == ' ' && arr[length - 1] == ' ')
    {
        count -= 2;
    }
    else if (arr[0] == ' ')
    {
        count--;
    }
    else if (arr[length - 1] == ' ')
    {
        count--;
    }
    printf("%d\n", count + 1);
    return 0;
}