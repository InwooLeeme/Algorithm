// 5800번 : 성적 통계

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int A = *(int *)a;
    int B = *(int *)b;
    if (A > B)
        return 1;
    else
        return -1;
    return 0;
}

int main()
{
    int test, count = 1;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int studentNumber;
        scanf("%d", &studentNumber);
        int *list;
        list = (int *)malloc(sizeof(int) * studentNumber);
        for (int j = 0; j < studentNumber; j++)
        {
            scanf("%d", &list[j]);
        }
        qsort(list, studentNumber, sizeof(int), compare);
        int gap = 0;
        for (int i = 1; i < studentNumber; i++)
        {
            if (gap < list[i] - list[i - 1])
            {
                gap = list[i] - list[i - 1];
            }
        }

        printf("Class %d\n", count);
        printf("Max %d, Min %d, Largest gap %d\n", list[studentNumber - 1], list[0], gap);
        count++;
        free(list);
    }
    return 0;
}