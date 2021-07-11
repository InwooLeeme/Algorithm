// 11098번 : 첼시를 도와줘!

#include <stdio.h>
#include <stdlib.h>
#define NAME_SIZE 21

typedef struct
{
    int price;
    char name[NAME_SIZE];
} Info;

int main()
{
    int test, max, idx;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int p;
        scanf("%d", &p);
        Info *list;
        list = (Info *)malloc(sizeof(Info) * p);
        max = 0;
        idx = 0;
        for (int i = 0; i < p; i++)
        {
            scanf("%d %s", &list[i].price, list[i].name);
            if (max < list[i].price)
            {
                max = list[i].price;
                idx = i;
            }
        }
        printf("%s\n", list[idx].name);
        free(list);
    }
    return 0;
}