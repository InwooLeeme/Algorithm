#include <stdio.h>

int main()
{
    int list[7];
    int sum = 0, min = 100, count = 0;
    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &list[i]);
        if (list[i] % 2 != 0)
        {
            sum += list[i];
            count++;
            if (min > list[i])
            {
                min = list[i];
            }
        }
    }
    if (count == 0)
    {
        printf("-1");
    }
    else
    {
        printf("%d\n", sum);
        printf("%d", min);
    }
    return 0;
}