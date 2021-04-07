// X 보다 작은 수

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 0, X = 0, i, k;
    scanf("%d %d", &N, &X);
    int *a = malloc(sizeof(int) * N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &k);
        if (k < X)
        {
            a[i] = k;
            printf("%d ", a[i]);
        }
        else
        {
            continue;
        }
    }
    free(a);
    return 0;
}