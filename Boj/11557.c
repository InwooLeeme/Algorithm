// 11557번 : Yangjojang of The Year

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[21];
    int price;
} University;

int compare(const void *a, const void *b)
{
    University A = *(University *)a;
    University B = *(University *)b;
    if (A.price > B.price)
    {
        return 1;
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
    int n;
    for (int i = 0; i < test; i++)
    {
        scanf("%d", &n);
        University *list;
        list = (University *)malloc(sizeof(University) * n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s %d", list[i].name, &list[i].price);
        }
        qsort(list, n, sizeof(University), compare);
        printf("%s\n", list[n - 1].name);
        free(list);
    }
    return 0;
}