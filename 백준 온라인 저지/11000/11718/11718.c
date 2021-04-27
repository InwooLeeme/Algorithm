// 11718 : 그대로 출력하기

#include <stdio.h>

int main()
{
    char s[100];
    while (scanf("%[^\n]\n", s) == 1) // %[^\n] : 공백 입력받기
    // 대괄호 안에 있는 ^는 부정을 의미한다 즉, 줄바꿈으로 시작하지 않는 모든 문자를 입력받으라는 것인데,
    // 마지막이 \n으로 끝나야하므로 한줄을 입력받아라는 소리
    // 대괄호 이후에 \n을 넣어주지 않으면 다음 반복문에서 s에 줄바꿈이 들어가기 때문에 줄바꿈까지 받아줘야한다.
    {
        printf("%s", s);
    }
    return 0;
}

#include <stdio.h>

int main()
{
    char s;
    while (scanf("%c", &s) != EOF)
    {
        printf("%c", s);
    }
    return 0;
}