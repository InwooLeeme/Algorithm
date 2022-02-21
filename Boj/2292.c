// 2292번 : 벌집
#include <stdio.h>

int main()
{
    int n = 0, i, ans = 1; // ans : 방 번호, i : 벌집의 중앙부터 방까지 칸의 갯수
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        ans += (i - 1) * 6;
        if (n <= ans)
        {
            break;
        }
    }
    printf("%d\n", i);
    return 0;
}