// 11719 : 그대로 출력하기 - 2

/* #include <stdio.h>

int main()
{
    char str[110];
    while (scanf("%[^\n]\n", str) == 1)
    {
        printf("%s", str);
    }
    return 0;
}
 */
#include <stdio.h>

int main()
{
    char str;
    while (scanf("%c", &str) != -1) // scanf는 에러값을 받거나 EOF를 받았을 시 return 값으로 -1을 반환한다.
    {
        printf("%c", str);
    }
    return 0;
}