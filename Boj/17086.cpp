#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define fastio cin.tie(0)->sync_with_stdio(0)
#define sz(v) (int)(v).size()
#define all(v) v.begin(), v.end()
#define rall(v) (v).rbegin(), (v).rend()
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)
#define debug(x) cout << (#x) << ": " << (x) << '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vs = vector<string>;
using tii = tuple<int, int, int>;
template <typename T>
using wector = vector<vector<T>>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll LNF = 1e18 + 7;

wector<int> adj(51, vector<int>(51, 0));
wector<int> dist(51, vector<int>(51, -1));
int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    queue<pii> Q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j])
                Q.push({i, j}), dist[i][j] = 0;
        }
    while (!Q.empty())
    {
        auto [curX, curY] = Q.front();
        Q.pop();
        for (int i = 0; i < 8; i++)
        {
            auto nx = curX + dx[i];
            auto ny = curY + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny] != -1)
                continue;
            dist[nx][ny] = dist[curX][curY] + 1;
            Q.push({nx, ny});
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = max(ans, dist[i][j]);
    cout << ans << "\n";
    return 0;
}