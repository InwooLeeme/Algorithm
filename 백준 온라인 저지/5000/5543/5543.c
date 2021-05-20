// 5543번 : 상근날드
#include <stdio.h>
#define hamSize 3
#define sodaSize 2

int hame[hamSize];
int soda[sodaSize];

int main()
{
    int a, b, c, minA = 2000, minB = 2000;
    scanf("%d%d%d", &hame[0], &hame[1], &hame[2]);
    for (int i = 0; i < hamSize; i++)
    {
        if (minA > hame[i])
        {
            minA = hame[i];
        }
    }
    scanf("%d%d", &soda[0], &soda[1]);
    for (int i = 0; i < sodaSize; i++)
    {
        if (minB > soda[i])
        {
            minB = soda[i];
        }
    }
    printf("%d\n", (minA + minB) - 50);
    return 0;
}