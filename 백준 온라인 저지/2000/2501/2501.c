#include <stdio.h>

int main()
{
    int answer[10001];
    int n, k = 0, i, count = 1;
    scanf("%d %d", &n, &k);
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            answer[count] = i;
            count++;
        }
    }
    printf("%d", answer[k]);
    return 0;
}