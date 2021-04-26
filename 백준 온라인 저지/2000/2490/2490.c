#include <stdio.h>

int main()
{
    int i = 4;
    while (i != 1)
    {
        int count = 0;
        int list[4] = {
            0,
        };
        for (int i = 0; i < 4; i++)
        {
            scanf("%d", &list[i]);
            if (list[i] == 1)
                count++; // 등일 때
        }
        switch (count)
        {
        case 1:
            printf("C\n");
            break;
        case 2:
            printf("B\n");
            break;
        case 3:
            printf("A\n");
            break;
        case 4:
            printf("E\n");
            break;
        default:
            printf("D\n");
            break;
        }
        i--;
    }

    return 0;
}