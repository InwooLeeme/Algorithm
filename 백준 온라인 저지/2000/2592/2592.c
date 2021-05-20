// 2592번 : 대표값

#include <stdio.h>
#define SIZE 10

int arr[SIZE];
int Array[SIZE * 150];

int main()
{
    int sum = 0, max = 0;
    for (int i = 0; i < SIZE; i++)
    {
        int num, left = 0;
        scanf("%d", &num);
        left = num / 10;
        Array[left]++;
        sum += num;
    }
    for (int j = 0; j < SIZE * 150; j++)
    {
        if (max < Array[j])
        {
            max = j;
        }
    }
    printf("%d\n%d", sum / SIZE, max * 10);
    return 0;
}