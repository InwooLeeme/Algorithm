// 5567번 : 결혼식

#include <stdio.h>
#define MAX 501

int components; // 연결 요소의 개수

int graph[MAX][MAX];
int visited[MAX];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        if (graph[1][i]) // 연결되어 있으면
        {
            visited[i] = 1; // 방문 배열을 방문함으로 표시
            for (int j = 2; j <= n; j++)
            {
                if (graph[i][j])
                {
                    visited[j] = 1; // 연결되어 있는 노드를 방문처리
                }
            }
        }
    }
    components = 0;
    for (int i = 2; i <= n; i++) // 자기자신(1)을 제외하기 때문에 2부터 시작
    {
        if (visited[i] == 1) // 방문되어 있으면 1과 연결되어 있다는 뜻
        {
            components++; // 그러면 친구의 갯수를 1증가시킴.
        }
    }
    printf("%d\n", components);
    return 0;
}