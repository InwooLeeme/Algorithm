#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0, result = 0;
    int *list;
    scanf("%d", &num);
    list = (int *)malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &list[i]);
    }
    if (num == 1)
    {
        result = list[0] * list[0];
    }
    else
    {
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num - 1; j++)
            {
                int temp;
                if (list[j] < list[j + 1])
                {
                    temp = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = temp;
                }
            }
        }
        result = list[0] * list[num - 1];
    }
    printf("%d", result);
    return 0;
}