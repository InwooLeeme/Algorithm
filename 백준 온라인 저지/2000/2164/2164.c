// 2164번 : 카드 2

#include <stdio.h>
#define MAX_QUEUE_SIZE 500001

int queue[MAX_QUEUE_SIZE];
int front = 0;
int rear = 0;
int count = 0;

void enqueue(int item)
{
    count++;
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    queue[rear] = item;
}

int dequeue()
{
    count--;
    front = (front + 1) % MAX_QUEUE_SIZE;
    return (queue[front]);
}

int size()
{
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        enqueue(i);
    }
    while (count != 1)
    {
        dequeue();
        enqueue(dequeue());
    }
    printf("%d\n", dequeue());
    return 0;
}