// 17103번 : 골드바흐 파티션

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX 1000001

int primeNumber[MAX];

// 에라토스테네스의 체 사용
void clearArray()
{
    for (int i = 2; i < MAX; i++)
    {
        primeNumber[i] = i;
    }
}

void setUpPrimeNumber()
{
    clearArray();
    for (int i = 2; i < MAX; i++)
    {
        if (primeNumber[i] == 0)
            continue;
        for (int j = i + i; j < MAX; j += i)
        {
            primeNumber[j] = 0;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    setUpPrimeNumber();
    while (t--)
    {
        int x;
        scanf("%d", &x);
        int a;
        int sum = 0;
        for (int i = 2; i <= x; i++)
        {
            a = i;
            if (x == (primeNumber[a] + primeNumber[x - a]))
            {
                sum++;
                if (primeNumber[a] == primeNumber[x - a])
                {
                    sum++;
                }
            }
        }

        printf("%d\n", sum / 2);
    }
    return 0;
}