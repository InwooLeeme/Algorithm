// 11004번 : K번째 수
// qsort사용
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    if (num1 < num2) // a가 b보다 작을 때는
        return -1;   // -1 반환

    if (num1 > num2) // a가 b보다 클 때는
        return 1;    // 1 반환

    return 0; // a와 b가 같을 때는 0 반환
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int *a = (int *)malloc(sizeof(int) * n);
    int arraySize = sizeof(a) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);
    printf("%d\n", a[k - 1]);
    free(a);
    return 0;
}