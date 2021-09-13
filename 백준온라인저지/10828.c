// 스택

#include <stdio.h>
#include <string.h>

int top_index = -1;

int main()
{
    int N, i = 0;
    scanf("%d", &N);
    int stack[10000];
    char order[N];
    for (i = 0; i < N; i++)
    {
        scanf("%s", &order[i]);
        if (strcmp(&order[i], "push") == 0)
        {
            int size = 0;
            scanf("%d", &size);
            stack[++top_index] = size;
        }
        else if (strcmp(&order[i], "top") == 0)
        {
            if (top_index == -1)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", stack[top_index]);
            }
        }
        else if (strcmp(&order[i], "pop") == 0)
        {
            // pop()
            if (top_index == -1)
            {
                printf("-1\n");
            }
            else
            {
                int top_value = stack[top_index--];
                printf("%d\n", top_value);
            }
        }
        else if (strcmp(&order[i], "size") == 0)
        {
            // size
            printf("%d\n", top_index + 1);
        }
        else
        {
            // empty()
            if (top_index == -1)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
    }
    return 0;
}