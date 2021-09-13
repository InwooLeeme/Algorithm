#include <stdio.h>
#include <string.h>
#define size 101

char arr[size];

int main()
{
    int count = 0;
    scanf("%s", arr);
    int length = strlen(arr);
    for (int i = 0; i < length; i++)
    {
        char x = arr[i];
        if (x == ',')
        {
            count++;
        }
    }
    printf("%d\n", count + 1);
    return 0;
}