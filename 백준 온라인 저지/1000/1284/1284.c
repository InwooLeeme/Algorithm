#include <stdio.h>

int getWidth(int n)
{
    int result = 2; // 양 옆 기본 cm
    while (n)
    {
        int temp = n % 10;
        switch (temp)
        {
        case 1:
            result += 2;
            break;
        case 0:
            result += 4;
            break;
        default:
            result += 3;
            break;
        }
        n /= 10;
        if (n)
        {
            result++;
        }
    }
    return result;
}

int main()
{
    while (1)
    {
        int num = 0;
        scanf("%d", &num);
        if (num == 0)
        {
            break;
        }
        printf("%d\n", getWidth(num));
    }

    return 0;
}