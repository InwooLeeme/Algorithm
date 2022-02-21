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

int board[9][9], dist[9][9];
int dx[] = {2, 1, 2, 1, -1, -2, -2, -1};
int dy[] = {1, 2, -1, -2, 2, 1, -1, -2};

void bfs(pii st)
{
    memset(dist, -1, sizeof dist);
    queue<pii> Q;
    dist[st.first][st.second] = 0;
    Q.push(st);
    while (!Q.empty())
    {
        auto curX = Q.front().first;
        auto curY = Q.front().second;
        Q.pop();
        for (int i = 0; i < 8; i++)
        {
            auto nx = curX + dx[i];
            auto ny = curY + dy[i];
            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
                continue;
            if (dist[nx][ny] != -1)
                continue;
            Q.push({nx, ny});
            dist[nx][ny] = dist[curX][curY] + 1;
        }
    }
}

//  parsing
pii pointParsing(string t)
{
    int x = t[0] - 'a';
    int y = abs(((t[1] - '0') - 8));
    return {x, y};
}

int32_t main()
{
    fastio;
    string a, b;
    cin >> a >> b;
    pii st = pointParsing(a);
    pii en = pointParsing(b);
    bfs(st);
    cout << dist[en.first][en.second] << "\n";
}