// 4963번 : 섬의 개수

#include <stdio.h>
#include <stdlib.h>
#define MAX 51
// 1 : 땅, 0 : 바다
int visited[MAX][MAX] = {
    0,
};
int graph[MAX][MAX] = {
    0,
};

int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};

void clear()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            graph[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

void dfs(int x, int y)
{
    visited[x][y] = 1;
    //graph[x][y] = 0;
    if (graph[x][y] == 0)
        return;
    int newX, newY;
    for (int i = 0; i < 8; i++)
    {
        newX = x + dx[i];
        newY = y + dy[i];
        if (0 < newX && newX < MAX && 0 < newY && newY < MAX)
        {
            if (visited[newX][newY] == 0 && graph[newX][newY] == 1)
            {
                dfs(newX, newY);
            }
        }
    }
}

int main()
{
    while (1)
    {
        int w, h;
        int count = 0;
        scanf("%d%d", &w, &h);
        if (w == 0 && h == 0)
            break;
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                scanf("%d", &graph[i][j]);
            }
        }
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                if (visited[i][j] == 0 && graph[i][j] == 1)
                {
                    dfs(i, j);
                    count++;
                }
            }
        }
        printf("%d\n", count);
        clear();
    }
    return 0;
}