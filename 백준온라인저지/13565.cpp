#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
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

int m, n;
bool vist[1001][1001];
int adj[1001][1001];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y)
{
    vist[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        auto nx = x + dx[i];
        auto ny = y + dy[i];
        if (vist[nx][ny] || adj[nx][ny])
            continue;
        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
        vist[nx][ny] = true;
        dfs(nx, ny);
    }
}

int main()
{
    //fastio;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &adj[i][j]);
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (!adj[0][j] && vist[0][j] == false)
            dfs(0, j);
    }
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (vist[m - 1][i])
            flag = true;
    }
    cout << (flag ? "YES" : "NO") << "\n";
    return 0;
}