#include <stdio.h>
#define size 10000

int fact(int n)
{
    int mem[size] = {
        0,
    };
    if (n == 1 || n == 0)
        return 1;
    if (mem[n] != 0)
        return mem[n];
    mem[n] = n * fact(n - 1);
    return mem[n];
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    printf("%d", fact(n));
    return 0;
}