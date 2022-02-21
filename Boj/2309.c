// 2309번 : 일곱난쟁이
#include <stdio.h>
#include <stdlib.h>

int arr[9];
int check[9];
int real[7];

int compare(const void *a, const void *b)
{
    int A = *(int *)a;
    int B = *(int *)b;
    if (A > B)
    {
        return 1;
    }
    else
    {
        return -1;
    }
    return 0;
}

int main()
{
    int sum = 0, start = 0, end = 0;
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    sum -= 100;
    int find = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                check[i] = check[j] = 1;
                find = 1;
                break;
            }
        }
        if (find)
        {
            break;
        }
    }
    int count = 0;
    for (int i = 0; i < 9; i++)
    {
        if (check[i] == 0)
        {
            real[count] = arr[i];
            count++;
        }
    }
    qsort(real, 7, sizeof(int), compare);
    for (int i = 0; i < 7; i++)
    {
        printf("%d\n", real[i]);
    }
    return 0;
}