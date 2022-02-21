// 7569번 : 토마토(3차원 실버 1)

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <math.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 100
#define X get<0>
#define Y get<1>
#define Z get<2>

using namespace std;

int board[MAX][MAX][MAX] = {
    0,
};
int dist[MAX][MAX][MAX] = {
    0,
};
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, 0, 0, -1, 1};
int dz[] = {0, 0, -1, 1, 0, 0};

int main()
{
    fastio;
    int m, n, h;
    cin >> m >> n >> h;
    queue<tuple<int, int, int>> Q;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> board[j][k][i];
                if (board[j][k][i] == 1)
                    Q.push({j, k, i});
                if (board[j][k][i] == 0)
                    dist[j][k][i] = -1;
            }
        }
    }
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 6; i++)
        {
            int newX = X(cur) + dx[i];
            int newY = Y(cur) + dy[i];
            int newZ = Z(cur) + dz[i];
            if (newX < 0 || newX >= n || newY < 0 || newY >= m || newZ < 0 || newZ >= h)
                continue;
            if (dist[newX][newY][newZ] != -1)
                continue;
            Q.push({newX, newY, newZ});
            dist[newX][newY][newZ] = dist[X(cur)][Y(cur)][Z(cur)] + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < h; k++)
            {
                if (dist[i][j][k] == -1)
                {
                    cout << "-1";
                    return 0;
                }
                ans = max(ans, dist[i][j][k]);
            }
        }
    }
    cout << ans;
    return 0;
}