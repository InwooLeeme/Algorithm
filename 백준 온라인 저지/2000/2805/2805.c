// 2805번 : 나무 자르기

#include <stdio.h>
#include <stdlib.h>

int height[1000000];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &height[i]);
    }
    int lo = 0, hi = 1000000000; // 불가능한 경우인 hi는 최댓값으로 놓고 시작
    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (height[i] > mid)
            {
                sum += height[i] - mid;
            }
        }
        if (sum >= m)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    printf("%d\n", lo);
    return 0;
}