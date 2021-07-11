// 1676번 : 팩토리얼 0의 개수

#include <stdio.h>

int main()
{
    int n, two = 0, five = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; i *= 2)
    {
        two += n / i;
    }
    for (int i = 5; i <= n; i *= 5)
    {
        five += n / i;
    }
    two < five ? printf("%d", two) : printf("%d", five);
    return 0;
}