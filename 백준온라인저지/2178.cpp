#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_cxx;

#define X first
#define Y second
#define int int64_t
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define Compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)
#define IDX(v, x) (lower_bound(all(v), x) - (v).begin())
#define debug(x) cout << (#x) << ": " << (x) << '\n'

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int, int, int>;
template <typename T>
using wector = vector<vector<T>>;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int32_t main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for (int i = 0; i < n; i++)
        cin >> board[i];
    wector<int> dist(n, vector<int>(m, -1));
    queue<pii> Q;
    dist[0][0] = 1;
    Q.push({0, 0});
    while (!Q.empty())
    {
        auto curX = Q.front().first;
        auto curY = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            auto nx = curX + dx[i];
            auto ny = curY + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] == '0' || dist[nx][ny] != -1)
                continue;
            dist[nx][ny] = dist[curX][curY] + 1;
            Q.push({nx, ny});
        }
    }
    cout << dist[n - 1][m - 1] << "\n";
}