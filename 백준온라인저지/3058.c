// 3058번 : 짝수를 찾아라

#include <stdio.h>
#define SIZE 7

int list[7];

int main()
{
    int t = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int sum = 0, min = 100;
        for (int i = 0; i < SIZE; i++)
        {
            scanf("%d", &list[i]);
            if (list[i] % 2 == 0)
            {
                sum += list[i];
                if (min > list[i])
                {
                    min = list[i];
                }
            }
        }
        printf("%d %d\n", sum, min);
    }
    return 0;
}