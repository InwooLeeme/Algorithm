#include <stdio.h>

int main()
{
    char list[4];
    int i = 0, result = 0, length = 0;
    scanf("%s", list);
    if (list[0] == '0')
    {
        return 0;
    }
    for (i = 0; i < 4; i++)
    {
        if (list[i] == '\0')
        {
            break;
        }
        else
        {
            length += 1;
        }
        if (list[i] == '0')
        {
            result += 4;
        }
        else if (list[i] == '1')
        {
            result += 2;
        }
        else
        {
            result += 3;
        }
    }
    switch (length)
    {
    case 1:
        result += 2;
        break;
    case 2:
        result += 3;
        break;
    case 3:
        result += 4;
        break;
    case 4:
        result += 5;
        break;
    }
    printf("%d\n", result);
    return 0;
}