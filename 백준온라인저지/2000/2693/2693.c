#include <stdio.h>
#define size 10

void sort(int arr[])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            int temp;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int t = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int arr[size] = {
            0,
        };
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &arr[j]);
        }
        sort(arr);
        printf("%d\n", arr[7]);
    }
    return 0;
}