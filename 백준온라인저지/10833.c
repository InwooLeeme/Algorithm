// 10833번 : 사과

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    int *apple, *student;
    scanf("%d", &test);
    int left = 0;
    apple = (int *)malloc(sizeof(int) * test);
    student = (int *)malloc(sizeof(int) * test);
    for (int i = 0; i < test; i++)
    {
        scanf("%d%d", &student[i], &apple[i]);
        left += apple[i] % student[i];
    }
    printf("%d\n", left);
    return 0;
}