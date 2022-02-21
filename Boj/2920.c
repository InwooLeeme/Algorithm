#include <stdio.h>
#define size 8

int arr[size];

int main()
{
    int count = 0, asc = 0, dsc = 0, down = 8;
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        int x = arr[i];
        if (x == i + 1)
        {
            asc++;
        }
        else if (x == down - i)
        {
            dsc++;
        }
        else
            continue;
    }
    if (asc == 8)
    {
        printf("ascending\n");
    }
    else if (dsc == 8)
    {
        printf("descending\n");
    }
    else
    {
        printf("mixed\n");
    }
    return 0;
}