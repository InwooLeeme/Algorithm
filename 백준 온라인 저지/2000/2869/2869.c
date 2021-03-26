#include <stdio.h>

int main()
{
    int a, b, v, result = 0;
    scanf("%d%d%d", &a, &b, &v); // a : 낮의 이동거리 , b : 밤에 미끄러진 거리, V : 정상까지의 거리
    result = (v - a) / (a - b);
    printf("%d", result + 1);
    return 0;
}