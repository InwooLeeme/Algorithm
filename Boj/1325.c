// 1325번 : 효율적인 해킹

#include <stdio.h>
#include <stdlib.h>
#define MAX 10001

int Graph[MAX][MAX];

int visited[MAX];

int answer[MAX];

void dfs(int v, int n)
{
    int components = 0;
    visited[v] = 1;
    printf("%d정점 방문\n", v);
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0 && Graph[v][i] == 1)
        {
            dfs(i, n);
        }
    }
    components++;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        Graph[x][y] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, n);
        }
    }
    return 0;
}