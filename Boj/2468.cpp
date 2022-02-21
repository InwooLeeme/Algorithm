// 2468번 : 안전영역(실버 1)

#include <iostream>
#include <algorithm>
#include <math.h>
#include <memory.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 101
using namespace std;

int n;
int graph[MAX][MAX];
bool vist[MAX][MAX];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y, int height) // height : 수심의 높이
{
    vist[x][y] = true;
    int newX, newY;
    for (int i = 0; i < 4; i++)
    {
        newX = x + dx[i];
        newY = y + dy[i];
        if (1 <= newX && newX <= n && 1 <= newY && newY <= n)
        {
            if (vist[newX][newY] == false && graph[newX][newY] > height) // 물에 잠기지 않은 경우에만 탐색
            {
                dfs(newX, newY, height);
            }
        }
    }
}

int main()
{
    cin >> n;
    int max_height = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
            if (max_height < graph[i][j])
            {
                max_height = graph[i][j];
            }
        }
    }
    int result = 0;
    for (int i = 0; i <= max_height; i++)
    {
        int count = 0;
        memset(vist, false, sizeof(vist));
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (vist[j][k] == false && graph[j][k] > i) //물에 잠기지 않은 경우만 탐색
                {
                    count++;
                    dfs(j, k, i);
                }
            }
        }
        result = max(result, count);
    }
    cout << result;
    return 0;
}