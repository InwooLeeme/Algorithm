#include <stdio.h>
#include <string.h>

void recursive(int n, char s)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", s);
    }
}

int main()
{
    char arr[21] = {
        0,
    };
    int test, r;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        scanf("%d %s", &r, arr);
        int length = strlen(arr);
        for (int j = 0; j < length; j++)
        {
            recursive(r, arr[j]);
        }
        printf("\n");
    }
    return 0;
}