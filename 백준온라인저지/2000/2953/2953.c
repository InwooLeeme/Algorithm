
// 2953번 : 나는 요리사다.

#include <stdio.h>
#define size 4
#define sumSize 5

int sum[sumSize];

int main()
{
    for (int i = 0; i < sumSize; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int num = 0;
            scanf("%d", &num);
            sum[i] += num;
        }
    }
    int max = sum[0], idx = 1;
    for (int i = 0; i < sumSize; i++)
    {
        if (max < sum[i])
        {
            max = sum[i];
            idx = i + 1;
        }
    }
    printf("%d ", idx);
    printf("%d\n", max);
    return 0;
}