// 3004번 : 체스판 조각

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int row = n / 2 + 1;
    int col = n - row + 2;
    printf("%d", row * col);
    return 0;
}