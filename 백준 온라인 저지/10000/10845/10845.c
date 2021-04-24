// 원형 큐 구현
#include <stdio.h>
#include <string.h>
#define MAX_QUEUE_SIZE 10000

typedef int element;
element count = 0, qFront = 0, rear = -1;
int queue[MAX_QUEUE_SIZE];

element empty()
{
    return (count == 0) ? 1 : 0;
}

void push(element item)
{
    rear += 1;
    count++;
    queue[rear] = item;
}

element pop()
{
    if (empty())
    {
        return -1;
    }
    count--;
    return queue[qFront++];
}

element size()
{
    return count;
}

element front()
{
    if (empty())
    {
        return -1;
    }
    return queue[qFront];
}

element back()
{
    if (empty())
    {
        return -1;
    }
    return queue[rear];
}

int main()
{
    int test = 0;
    char input[7];
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        scanf("%s", input);
        if (strcmp(input, "push") == 0)
        {
            int n = 0;
            scanf("%d", &n);
            push(n);
        }
        else if (strcmp(input, "pop") == 0)
        {
            printf("%d\n", pop());
        }
        else if (strcmp(input, "size") == 0)
        {
            printf("%d\n", size());
        }
        else if (strcmp(input, "front") == 0)
        {
            printf("%d\n", front());
        }
        else if (strcmp(input, "back") == 0)
        {
            printf("%d\n", back());
        }
        else
        {
            printf("%d\n", empty());
        }
    }
    return 0;
}