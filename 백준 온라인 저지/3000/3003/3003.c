// 3003번 : 킹, 퀸, 룩, 비숍, 나이트, 폰
#include <stdio.h>

int main()
{
    int k, q, l, bs, kn, po;
    scanf("%d%d%d%d%d%d", &k, &q, &l, &bs, &kn, &po);
    printf("%d ", 1 - k);
    printf("%d ", 1 - q);
    printf("%d ", 2 - l);
    printf("%d ", 2 - bs);
    printf("%d ", 2 - kn);
    printf("%d ", 8 - po);
    return 0;
}