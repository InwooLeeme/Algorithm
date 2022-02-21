#include <stdio.h>
#include <string.h>
#define size 11

void bubbleSort(char *arr) // 버블 정렬 활용
{
    for (int i = 0; i < strlen(arr); i++)
    {
        for (int j = 0; j < strlen(arr) - 1; j++)
        {
            char temp;
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    char arr[size]; //문자열로 입력 받음
    scanf("%s", arr);
    bubbleSort(arr);
    for (int i = 0; i < strlen(arr); i++)
    {
        printf("%c", arr[i]);
    }
    return 0;
}