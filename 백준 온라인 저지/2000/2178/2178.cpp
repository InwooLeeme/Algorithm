// 2178번 : 미로 탐색(실버 1)

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, M;
int map[100][100] = {0};
bool visited[100][100];
int cnt[100][100] = {0};

int dx[] = {0, 1, 0, -1}; //12시부터 시계방향
int dy[] = {-1, 0, 1, 0};

void bfs(int x, int y)
{
    visited[x][y] = true;
    cnt[x][y]++;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newX = xx + dx[i];
            int newY = yy + dy[i];

            if (newX >= 0 && newX < N && newY >= 0 && newY < M && !visited[newX][newY] && map[newX][newY] == 1)
            {
                visited[newX][newY] = true;
                q.push({newX, newY});
                cnt[newX][newY] = cnt[xx][yy] + 1;
            }
        }
    }
}
int main(void)
{
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    bfs(0, 0);
    cout << cnt[N - 1][M - 1];

    return 0;
}