// 2711번 : 오타맨 고창영

#include <stdio.h>
#include <string.h>
#define SIZE 81

int main()
{
    int test;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int n;
        char arr[SIZE] = {
            0,
        };
        scanf("%d %s", &n, arr);
        int length = strlen(arr);
        for (int j = 0; j < n - 1; j++)
        {
            printf("%c", arr[j]);
        }
        for (int j = n; j < length; j++)
        {
            printf("%c", arr[j]);
        }
        printf("\n");
    }
    return 0;
}