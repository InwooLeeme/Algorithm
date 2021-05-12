// 4673번 : 셀프 넘버
#include <stdio.h>
#define size 10001

int arr[size];

void getSelfNumber(int n)
{
    int sum = n;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    arr[sum] = 1;
}

int main()
{
    for (int i = 1; i <= size - 1; i++)
    {
        getSelfNumber(i);
        if (arr[i] != 1)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}