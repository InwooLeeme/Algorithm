// 11724번 : 연결 요소의 갯수

#include <stdio.h>
#define MAX 1001

int Graph[MAX][MAX] = {
    0,
};
int visited[MAX] = {
    0,
};

void DFS(int v, int n)
{
    visited[v] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (Graph[v][i] == 1 && visited[i] == 0)
        {
            DFS(i, n);
        }
    }
}

int main()
{
    int n, m, v; // n :정점의 수, m : 간선의 수
    int components = 0;
    scanf("%d%d", &n, &m);
    int x, y;
    scanf("%d%d", &x, &y);
    Graph[x][y] = 1;
    Graph[y][x] = 1;
    v = x; // 초기 정점을 처음 들어온 x값으로 설정
    for (int i = 1; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        Graph[x][y] = 1;
        Graph[y][x] = 1;
    }
    // visited배열을 정점의 수 만큼 돌면서 방문하지 않은 정점이 있다면 dfs를 실행
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            DFS(i, n);
            components += 1; // 연결 요소(컴포넌트)의 수를 1 증가시킴
        }
    }
    printf("%d\n", components);
    return 0;
}