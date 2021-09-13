// 9020번 : 골드바흐의 추측
#include <stdio.h>
#define MAX 10001

int list[MAX] = {
    0,
};

void getPrimeNumber()
{
    for (int i = 2; i < MAX; i++)
    {
        list[i] = 1;
    }
    // 에라토스테네스의 체 구현
    for (int i = 2; i < MAX; i++)
    {
        if (list[i] == 0)
            continue;
        for (int j = i + i; j < MAX; j += i)
        {
            if (list[j] == 0)
                continue;
            else
                list[j] = 0;
        }
    }
}

int main()
{
    int test;
    scanf("%d", &test);
    getPrimeNumber();
    /* for (int i = 0; i < MAX; i++)
    {
        if (list[i] == 1)
        {
            printf("%d ", i);
        }
    } */
    while (test--)
    {
        int n;
        scanf("%d", &n);
        for (int j = n / 2; j > 0; j--)
        {
            if (list[j] != 0 && list[n - j] != 0)
            {
                printf("%d %d\n", j, n - j);
                break;
            }
        }
    }
    return 0;
}