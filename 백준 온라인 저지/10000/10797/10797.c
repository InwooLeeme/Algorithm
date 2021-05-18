#include <stdio.h>

int main()
{
    int key, count = 0;
    scanf("%d", &key);
    for (int i = 0; i < 5; i++)
    {
        int num = 0;
        scanf("%d", &num);
        if (key == num)
            count++;
    }
    printf("%d\n", count);
    return 0;
}