#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    printf("%s", (n % 2 != 0) ? "SK" : "CY");
    // 시뮬레이션 결과 홀수이면 무조건 SK가 이김.
    return 0;
}