#include <stdio.h>
#include <string.h>
#define size 101

int main()
{
    char list[size] = {0};
    scanf("%s", list);
    printf("%c", list[0]); // 공백 문자가 들어올 수도 있으니 배열의 0번째는 무조건 출력
    for (int i = 1; i < strlen(list); i++)
    {
        if (i % 10 == 0)
            printf("\n");
        printf("%c", list[i]);
    }
    return 0;
}