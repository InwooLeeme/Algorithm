// 10451번 : 순열 사이클

#include <stdio.h>
#define MAX 1001

int graph[MAX][MAX];
int visited[MAX];

void dfs(int v, int n)
{
    visited[v] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0 && graph[v][i] == 1)
        {
            dfs(i, n);
        }
    }
}

void clearVisitedArray()
{
    for (int i = 0; i < MAX; i++)
    {
        visited[i] = 0;
        for (int j = 0; j < MAX; j++)
        {
            graph[i][j] = 0;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int idx = 1;
        int n = 0, components = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            graph[idx][x] = 1;
            idx++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i, n);
                components++;
            }
        }
        printf("%d\n", components);
        clearVisitedArray();
    }
    return 0;
}