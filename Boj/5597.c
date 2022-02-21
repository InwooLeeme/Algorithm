
// 5597번 : 과제 안 내신 분..?

#include <stdio.h>
#define size 30

int arr[size];

int main()
{
    for (int i = 1; i <= 28; i++)
    {
        int num = 0;
        scanf("%d", &num);
        for (int j = 1; j <= size; j++)
        {
            if (num == j)
            {
                arr[num] = 1;
            }
        }
    }
    printf("\n");
    for (int i = 1; i <= size; i++)
    {
        if (arr[i] == 0)
            printf("%d\n", i);
    }
    return 0;
}