#include <stdio.h>

int main()
{
    int n = 0, zCount = 0, nCount = 0; // zCount : 0만 카운트, nCount : 0이 아닌수 카운트
    int list[102];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
        if (list[i] == 0)
        {
            zCount++;
        }
        else
        {
            nCount++;
        }
    }
    if (zCount > nCount)
    {
        printf("Junhee is not cute!");
    }
    else
    {
        printf("Junhee is cute!");
    }
    return 0;
}