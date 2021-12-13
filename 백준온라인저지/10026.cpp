#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int int64_t
using namespace std;

int board[101][101], n;
bool vist[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y, int color)
{
    if (vist[x][y])
        return;
    vist[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if (vist[nx][ny] || board[nx][ny] != color)
            continue;
        dfs(nx, ny, color);
    }
}

int32_t main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if (c == 'R')
                board[i][j] = 1;
            if (c == 'G')
                board[i][j] = 2;
            if (c == 'B')
                board[i][j] = 3;
        }
    }
    int isNotRGB[3] = {0, 0, 0}, isRGB[2] = {0, 0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vist[i][j] && board[i][j] == 1)
            {
                isNotRGB[0]++;
                dfs(i, j, 1);
            }
            if (!vist[i][j] && board[i][j] == 2)
            {
                isNotRGB[1]++;
                dfs(i, j, 2);
            }
            if (!vist[i][j] && board[i][j] == 3)
            {
                isNotRGB[2]++;
                dfs(i, j, 3);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 2)
                board[i][j] = 1;
        }
    }
    for (int i = 0; i < 101; i++)
    {
        fill(vist[i], vist[i] + 101, false);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vist[i][j] && board[i][j] == 1)
            {
                isRGB[0]++;
                dfs(i, j, 1);
            }
            if (!vist[i][j] && board[i][j] == 3)
            {
                isRGB[1]++;
                dfs(i, j, 3);
            }
        }
    }
    cout << accumulate(isNotRGB, isNotRGB + 3, 0) << " " << accumulate(isRGB, isRGB + 2, 0) << "\n";
}