#include <stdio.h>

int main()
{
    int number = 0, count = 0, first = 0;
    scanf("%d", &number);
    first = number;
    while (1)
    {
        int a = 0, b = 0, temp;
        a = number / 10;
        b = number % 10;
        temp = a + b;
        number = (b * 10) + (temp % 10);
        count += 1;
        if (first == number)
        {
            break;
        }
    }
    printf("%d\n", count);
    return 0;
}