#include <stdio.h>
#define size 9

int main()
{
    int max = 0, rowAn = 0, colAn = 0;
    int arr[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                rowAn = i;
                colAn = j;
            }
        }
    }
    printf("%d\n%d %d", max, rowAn + 1, colAn + 1);
}