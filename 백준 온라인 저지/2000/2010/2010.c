// 2010번 : 플러그

#include <stdio.h>

int main()
{
    int n, sum = 0, num = 0;
    scanf("%d", &n);
    scanf("%d", &num);
    sum = num;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &num);
        sum += num - 1;
    }
    printf("%d\n", sum);
    return 0;
}