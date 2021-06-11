// 10825번 : 국영수

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[11];
    int english;
    int math;
    int goo;
} Score;

int compare(const void *a, const void *b)
{
    Score A = *(Score *)a;
    Score B = *(Score *)b;
    if (A.goo < B.goo)
    {
        return 1;
    }
    else if (A.goo == B.goo)
    {
        if (A.english > B.english)
        {
            return 1;
        }
        else if (A.english == B.english)
        {
            if (A.math < B.math)
            {
                return 1;
            }
            else if (A.math == B.math)
            {
                return strcmp(A.name, B.name);
            }
        }
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    Score *list;
    list = (Score *)malloc(sizeof(Score) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d%d%d", list[i].name, &list[i].goo, &list[i].english, &list[i].math);
    }
    qsort(list, n, sizeof(Score), compare);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", list[i].name);
    }
    free(list);
    return 0;
}