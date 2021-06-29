// 1182번 : 부분수열의 합

#include <stdio.h>

int count, currentSum;
int n, s;

int val[20];

void dfs(int currentIndex)
{
    if (currentIndex == n)
        return;
    // 현재까지의 합이 S면 갯수를 1증가
    if (s == currentSum + val[currentIndex])
    {
        count++;
    }
    // 이번 원소를 포함시키지 않고 시도
    dfs(currentIndex + 1);

    // 이번 원소를 포함시키고 시도
    currentSum += val[currentIndex];
    dfs(currentIndex + 1);
    // 마지막에 다시 이번 원소를 빼 줘야함
    currentSum -= val[currentIndex];
}

int main()
{
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val[i]);
    }
    dfs(0);
    printf("%d\n", count);
    return 0;
}