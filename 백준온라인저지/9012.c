#include <stdio.h>
#include <string.h>

int main()
{
    int t = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        char input[60];
        int count = 0;
        scanf("%s", input);
        int length = strlen(input);
        for (int j = 0; j < length; j++)
        {
            char str = input[j];
            if (str == '(')
            {
                count++;
            }
            else if (str == ')')
            {
                count--;
            }
            if (count < 0)
            {
                break;
            }
        }
        if (count == 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}