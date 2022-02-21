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
#define OOB(x, y) ((x) < 0 || (x) >= m || (y) < 0 || (y) >= n)
#define debug(x) cout << (#x) << ": " << (x) << '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using tii = tuple<int, int, int>;
template <typename T>
using wector = vector<vector<T>>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll LNF = 1e18 + 7;

int adj[251][251];
bool vist[251][251];
int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};
int m, n;

void bfs(int x, int y)
{
    queue<pii> Q;
    Q.push({x, y});
    vist[x][y] = true;
    while (!Q.empty())
    {
        auto [curX, curY] = Q.front();
        Q.pop();
        for (int i = 0; i < 8; i++)
        {
            auto nx = curX + dx[i];
            auto ny = curY + dy[i];
            if (OOB(nx, ny) || vist[nx][ny] || !adj[nx][ny])
                continue;
            Q.push({nx, ny});
            vist[nx][ny] = true;
        }
    }
}

int main()
{
    fastio;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
    int components = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] && !vist[i][j])
            {
                bfs(i, j);
                components++;
            }
        }
    }
    cout << components << "\n";
    return 0;
}