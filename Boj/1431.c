//1431번 : 시리얼 번호

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[51];
} String;

int sum(String Str)
{
    int result = 0;
    int legnth = strlen(Str.name);
    for (int i = 0; i < legnth; i++)
    {
        if (Str.name[i] <= '9' && Str.name[i] >= '0')
        {
            result += (Str.name[i] - '0');
        }
        else
            continue;
    }
    return result;
}

int compare(const void *a, const void *b)
{
    String A = *(String *)a;
    String B = *(String *)b;
    int aLength = strlen(A.name);
    int bLength = strlen(B.name);
    int sumA = sum(A);
    int sumB = sum(B);
    if (aLength != bLength)
    {
        return (aLength > bLength);
    }
    else if (sumA != sumB)
    {
        return (sumA > sumB);
    }
    else
    {
        return strcmp(A.name, B.name);
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    String *list;
    list = (String *)malloc(sizeof(String) * t);
    for (int i = 0; i < t; i++)
    {
        scanf("%s", list[i].name);
    }
    qsort(list, t, sizeof(String), compare);
    for (int i = 0; i < t; i++)
    {
        printf("%s\n", list[i].name);
    }
    free(list);
    return 0;
}