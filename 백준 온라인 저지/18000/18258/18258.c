// 18258번 : 큐 2

#include <stdio.h>
#include <string.h>
#define MAX_QUEUE_SIZE 2000001
#define INPUT_SIZE 10

typedef struct
{
    int data[MAX_QUEUE_SIZE];
    int rear;
    int front;
} QueueType;

char input[INPUT_SIZE];

void initQueue(QueueType *q)
{
    q->front = -1;
    q->rear = -1;
}

int empty(QueueType *q)
{
    return q->front == q->rear;
}

void push(QueueType *q, int item)
{
    q->data[++(q->rear)] = item;
}

int size(QueueType *q)
{
    return q->rear - q->front;
}

int pop(QueueType *q)
{
    if (empty(q))
    {
        return -1;
    }
    return q->data[++(q->front)];
}

int front(QueueType *q)
{
    if (empty(q))
    {
        return -1;
    }
    return q->data[q->front + 1];
}

int back(QueueType *q)
{
    if (empty(q))
    {
        return -1;
    }
    return q->data[q->rear];
}

void clear()
{
    for (int i = 0; i < INPUT_SIZE; i++)
    {
        input[i] = 0;
    }
}

int main()
{
    int test;
    scanf("%d", &test);
    QueueType q;
    initQueue(&q);
    while (test--)
    {
        scanf("%s", input);
        if (!strcmp(input, "push"))
        {
            int x;
            scanf("%d", &x);
            push(&q, x);
        }
        else if (!strcmp(input, "pop"))
        {
            int x = pop(&q);
            printf("%d\n", x);
        }
        else if (!strcmp(input, "size"))
        {
            int x = size(&q);
            printf("%d\n", x);
        }
        else if (!strcmp(input, "empty"))
        {
            int x = empty(&q);
            printf("%d\n", x);
        }
        else if (!strcmp(input, "front"))
        {
            int x = front(&q);
            printf("%d\n", x);
        }
        else
        {
            int x = back(&q);
            printf("%d\n", x);
        }
        clear();
    }
    return 0;
}