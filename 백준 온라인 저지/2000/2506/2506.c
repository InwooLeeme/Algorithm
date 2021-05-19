// 2506번 : 점수 계산

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, combo = 0, score = 0, count = 0;
    scanf("%d", &n);
    int *list;
    list = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &list[i]);
        if (list[i] == 1)
        {
            score += 1;
            count++;
            //combo++;
            if (count >= 2)
            {
                combo++;
                score += combo;
            }
        }
        else
        {
            count = 0;
            combo = 0;
            continue;
        }
    }
    printf("%d", score);
    free(list);
    return 0;
}