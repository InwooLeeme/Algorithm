#include <stdio.h>

int main()
{
    int T, a, b, i = 0;
    int result[100] = {
        0,
    };
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%d %d", &a, &b);
        result[i] = a + b;
    }
    for (i = 0; i < T; i++)
    {
        if (result[i] == '\0')
        {
            break;
        }
        else
        {
            printf("%d\n", result[i]);
        }
    }
    return 0;
}