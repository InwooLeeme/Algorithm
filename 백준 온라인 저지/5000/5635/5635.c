// 5635번 : 생일

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[16];
    int day;
    int month;
    int year;
} Birthday;

int compare(const void *a, const void *b)
{
    Birthday A = *(Birthday *)a;
    Birthday B = *(Birthday *)b;
    if (A.year > B.year)
    {
        return 1;
    }
    else if (A.year == B.year)
    {
        if (A.month > B.month)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
    return 0;
}

int main()
{
    int test;
    scanf("%d", &test);
    Birthday *list;
    list = (Birthday *)malloc(sizeof(Birthday) * test);
    for (int i = 0; i < test; i++)
    {
        scanf("%s %d %d %d", list[i].name, &list[i].day, &list[i].month, &list[i].year);
    }
    qsort(list, test, sizeof(Birthday), compare);
    printf("%s\n%s", list[test - 1].name, list[0].name);
    free(list);
    return 0;
}