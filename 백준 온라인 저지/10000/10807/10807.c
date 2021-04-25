#include <stdio.h>

int main()
{
    int n = 0, v = 0, count = 0;
    int list[101] = {
        0,
    };
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
    }
    scanf("%d", &v);
    for (int i = 0; i < n; i++)
    {
        if (v == list[i])
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}