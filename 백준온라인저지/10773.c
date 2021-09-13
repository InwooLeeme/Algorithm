#include <stdio.h>
#define MAX_STACK_SIZE 100000

typedef int element;
element stack[MAX_STACK_SIZE];
int top = 0;
void push(element item)
{
    stack[top] = item;
    top++;
}

void pop()
{
    stack[top] = 0;
    top--;
}

int main()
{
    int k = 0, sum = 0;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int temp = 0;
        scanf("%d", &temp);
        if (temp == 0)
        {
            pop();
        }
        else
        {
            push(temp);
        }
    }
    for (int i = 0; i < top; i++)
    {
        sum += stack[i];
    }
    printf("%d\n", sum);
    return 0;
}