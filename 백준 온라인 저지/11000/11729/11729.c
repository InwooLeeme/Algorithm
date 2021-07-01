// 11729번 : 하노이 탑 이동 순서(실버 2)

#include <stdio.h>
#include <math.h>

void move(int n, int start, int middle, int end)
{
    if (n == 1)
    {
        printf("%d %d\n", start, end);
        return;
    }
    move(n - 1, start, end, middle); // n - 1개를 1번에서 2번으로 옮긴다.
    move(1, start, middle, end);     // n번째를 1번에서 3번 막대로 옮긴다.
    move(n - 1, middle, start, end); // n - 1번째를 2번에서 3번으로 옮긴다.
}

int main()
{
    int n;
    scanf("%d", &n);
    int count = pow(2, n) - 1;
    printf("%d\n", count);
    move(n, 1, 2, 3);
    return 0;
}