#include <stdio.h>

int main(void)
{
    unsigned long long x, y;
    scanf("%llu%llu", &x, &y);
    /*
	3가지 경우 존재
	x>y, x=y, x<y
	*/
    if (x > y)
    {
        printf("%.llu\n", x - y - 1);
        while (x - 1 > y)
            printf("%llu ", ++y);
    }
    else if (x == y)
    {
        printf("0\n");
    }
    else
    {
        printf("%llu\n", y - x - 1);
        while (y - 1 > x)
            printf("%llu ", ++x);
    }
    return 0;
}