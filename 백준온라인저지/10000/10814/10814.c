// 10814번 : 나이순 정렬

#include <stdio.h>
#include <stdlib.h>
#define NAME_SIZE 101

typedef struct
{
    char name[NAME_SIZE];
    int age;
    int number;
} List;

int compare(const void *a, const void *b)
{
    List num1 = *(List *)a;
    List num2 = *(List *)b;
    if (num1.age > num2.age)
    {
        return 1;
    }
    else if (num1.age == num2.age)
    {
        if (num1.number > num2.number)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    return 0;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    List *arr;
    arr = (List *)malloc(sizeof(List) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &(arr[i].age), arr[i].name);
        arr[i].number = i;
    }
    qsort(arr, n, sizeof(List), compare);
    for (int i = 0; i < n; i++)
    {
        printf("%d %s\n", arr[i].age, arr[i].name);
    }
    free(arr);
    return 0;
}