#include <stdio.h>
#include <stdlib.h>

int main()
{
    int min, max, N = 0, i;
    scanf("%d", &N);
    int *s = malloc(sizeof(int) * N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &s[i]);
    }
    min = s[0];
    max = s[0];
    for (i = 1; i < N; i++)
    {
        if (s[i] < min)
        {
            min = s[i];
        }
        if (s[i] > max)
        {
            max = s[i];
        }
    }
    printf("%d %d", min, max);
    free(s);
    return 0;
}