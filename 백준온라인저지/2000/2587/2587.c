#include <stdio.h>

int main()
{
    int list[5];
    int sum = 0, mid = 0;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &list[i]);
        sum += list[i];
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int temp = 0;
            if (list[j] > list[j + 1])
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    printf("%d\n", sum / 5);
    printf("%d\n", list[2]);
    return 0;
}