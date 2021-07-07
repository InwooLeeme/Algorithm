// 7576번 : 토마토(실버 1)

#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000
using namespace std;

int board[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int m, n; // m : 가로칸 수, n : 세로 칸 수
    fastio;
    queue<pair<int, int>> q;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                q.push(make_pair(i, j));
            }
            if (board[i][j] == 0)
            {
                dist[i][j] = -1;
            }
        }
    }
    while (!q.empty())
    {
        auto cur = q.front(); // 현재 큐에 있는 좌표 pair값
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newX = cur.first + dx[i];
            int newY = cur.second + dy[i];
            if (0 > newX || newX >= n || 0 > newY || newY >= m)
                continue;
            if (dist[newX][newY] != -1)
                continue;
            q.push(make_pair(newX, newY));
            dist[newX][newY] = dist[cur.first][cur.second] + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] == -1)
            {
                cout << '-1' << "\n";
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
    return 0;
}