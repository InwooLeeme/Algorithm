#include <stdio.h>
#include <string.h>
#define size 1001

char arr[size];
char doctor[size];

int main()
{
    scanf("%s", arr);
    scanf("%s", doctor);
    int doctorLength = strlen(doctor);
    int arrLength = strlen(arr);
    if (doctorLength > arrLength)
    {
        printf("no\n");
    }
    else
    {
        printf("go\n");
    }
    return 0;
}