// 9093번 : 단어 뒤집기

#include <stdio.h>

int main(void)
{
    char word[1001];
    int n;
    int i = 0;
    int cnt = -1;
    char stack[20];

    scanf("%d", &n);
    getchar();
    while (n--)
    {
        fgets(word, 1001, stdin);
        while (word[i])
        {
            if (word[i] == ' ' || word[i] == '\n')
            {
                while (cnt >= 0)
                {
                    printf("%c", stack[cnt--]); // 단어를 뒤집어서 출력
                }
                printf("%c", word[i]); // 공백을 출력
            }
            else
            {
                // 단어일 때
                stack[++cnt] = word[i]; // 스택에 삽입
            }
            i++;
        }
        // 1개의 문장이 끝나면 초기화를 시킴
        i = 0;
        cnt = -1;
    }
    return 0;
}