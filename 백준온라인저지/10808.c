#include <stdio.h>
#include <string.h>
#define size 101
#define alphaSize 26

char arr[size];
char alpha[alphaSize];

int main()
{
    scanf("%s", arr);
    int length = strlen(arr);
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j <= alphaSize; j++)
        {
            if ((int)arr[i] == (j + 97))
            {
                alpha[j]++;
            }
        }
    }
    for (int i = 0; i < alphaSize; i++)
    {
        printf("%d ", alpha[i]);
    }
    return 0;
}
