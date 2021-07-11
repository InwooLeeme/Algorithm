#include <stdio.h>
#define size 300

int main()
{
    int n, m, k;
    int arr[size][size] = {
        0,
    };
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d", &k);
    int a, b, x, y;
    for (int i = 0; i < k; i++)
    {
        int sum = 0;
        scanf("%d %d %d %d", &a, &b, &x, &y);
        for (int i = a - 1; i < x; i++)
        {
            for (int j = b - 1; j < y; j++)
            {
                sum += arr[i][j];
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}