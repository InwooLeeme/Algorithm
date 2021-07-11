// 1158번 : 요세푸스 문제
#include <stdio.h>
#define MAX 5000

int queue[MAX + 1];
int front = 0; //큐의 앞
int rear = 0;  // 큐의 뒤
int size = 0;  // 큐 안에 들어가있는 요소들

// 원형 큐 push
void enqueue(int item)
{
    rear = (rear + 1) % MAX;
    queue[rear] = item;
    size++;
}

// 원형 큐 pop
int dequeue()
{
    front = (front + 1) % MAX;
    size--;
    return queue[front];
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        enqueue(i); // 1~n까지의 값 큐에 넣기
    }
    int idx = 0; // 현재 몇명이 제거되었는지 확인하는 변수
    printf("<");
    while (size != 0)
    {
        for (int i = 1; i <= k; i++)
        {
            if (i == k)
            {
                ++idx;
                if (idx == n)
                {
                    printf("%d", dequeue());
                }
                else
                {
                    printf("%d, ", dequeue());
                }
            }
            else
            {
                enqueue(dequeue());
            }
        }
    }
    printf(">");
    return 0;
}