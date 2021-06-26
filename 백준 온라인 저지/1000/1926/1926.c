// 1926번 : 그림

#include <stdio.h>
#define MAX 500

int graph[MAX][MAX];
int visited[MAX][MAX];
int components;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int answer[MAX];

int floodfill(int x, int y)
{
    visited[x][y] = 1;
    int newX, newY;
    components++; // 연결 요소의 개수 증가
    for (int i = 0; i < 4; i++)
    {
        newX = x + dx[i];
        newY = y + dy[i];
        if (0 <= newX && newX < MAX && 0 <= newY && newY < MAX)
        {
            if (visited[newX][newY] == 0 && graph[newX][newY] == 1)
            {
                floodfill(newX, newY);
            }
        }
    }
    return components;
}

int main()
{
    int n, m, i = 0, j = 0, count = 0;
    int max = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && graph[i][j] == 1)
            {
                components = 0;
                answer[count] = floodfill(i, j);
                count++;
            }
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++)
    {
        if (max < answer[i])
        {
            max = answer[i];
        }
    }
    printf("%d", max);
    return 0;
}