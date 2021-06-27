// 1743번 : 음식물 피하기

#include <stdio.h>
#define MAX 101

int visited[MAX][MAX] = {
    0,
};
int graph[MAX][MAX] = {
    0,
};
int answer[MAX] = {
    0,
};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int components, n, m, k;

int floodfill(int x, int y, int n, int m)
{
    visited[x][y] = 1;
    components++;
    int newX, newY;
    for (int i = 0; i < 4; i++)
    {
        newX = x + dx[i];
        newY = y + dy[i];
        if (0 < newX && newX <= n && 0 < newY && newY <= m)
        {
            if (visited[newX][newY] == 0 && graph[newX][newY] == 1)
            {
                floodfill(newX, newY, n, m);
            }
        }
    }
    return components;
}

int main()
{
    int count = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++)
    {
        int r, c;
        scanf("%d%d", &r, &c);
        graph[r][c] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (visited[i][j] == 0 && graph[i][j] == 1)
            {
                components = 0;
                answer[count] = floodfill(i, j, n, m);
                count++;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < count; i++)
    {
        if (max < answer[i])
        {
            max = answer[i];
        }
    }
    printf("%d\n", max);
    return 0;
}