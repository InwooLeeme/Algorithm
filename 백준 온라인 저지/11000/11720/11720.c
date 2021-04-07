#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 0, i;
    long long result = 0;
    scanf("%d", &N);
    char *ch = malloc(sizeof(int) * N);
    scanf("%s", ch);
    for (i = 0; i < N; i++)
    {
        result = result + (ch[i] - '0');
    }
    printf("%lld", result);
    free(ch);
    return 0;
}