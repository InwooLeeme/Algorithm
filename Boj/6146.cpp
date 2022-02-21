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

int adj[1001][1001];
wector<int> dist(1001, vector<int>(1001, -1));
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main()
{
    fastio;
    int x, y, n;
    cin >> x >> y >> n;
    queue<pii> Q;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a + 500][b + 500] = INF;
    }
    Q.push({500, 500});
    dist[500][500] = 0;
    while (!Q.empty())
    {
        auto [curX, curY] = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            auto nx = curX + dx[i];
            auto ny = curY + dy[i];
            if (nx < 0 || nx > 1000 || ny < 0 || ny > 1000)
                continue;
            if (dist[nx][ny] != -1 || adj[nx][ny] == INF)
                continue;
            dist[nx][ny] = dist[curX][curY] + 1;
            Q.push({nx, ny});
        }
    }
    cout << dist[x + 500][y + 500] << "\n";
    return 0;
}