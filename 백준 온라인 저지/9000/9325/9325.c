#include <stdio.h>

int main()
{
    int test;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int s = 0, totalPrice = 0; // 자동차의 가격,총 가격
        scanf("%d", &s);
        totalPrice += s;
        int optionNumber;
        scanf("%d", &optionNumber);
        for (int i = 0; i < optionNumber; i++)
        {
            int q, p;
            scanf("%d%d", &q, &p);
            totalPrice += (q * p);
        }
        printf("%d\n", totalPrice);
    }
    return 0;
}