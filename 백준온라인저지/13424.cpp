// 13424번 : 비밀 모임

#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) int((a).size())
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using wector = vector<vector<int>>;
using tiii = tuple<int, int, int>;

const int INF = int(1e9) + 7;
int n, m, k;

int dist[101][101];

void reset()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dist[i][j] = i == j ? 0 : INF;
        }
    }
}

void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main()
{
    fastio;
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        reset();
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            dist[a][b] = min(dist[a][b], c);
            dist[b][a] = min(dist[b][a], c);
        }
        cin >> k;
        vi v(k);
        for (int i = 0; i < k; i++)
            cin >> v[i];
        floyd();
        int ans = INF, c = 0;
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < v.size(); j++)
            {
                cnt += dist[v[j]][i];
            }
            if (ans > cnt)
            {
                ans = cnt;
                c = i;
            }
        }
        cout << c << "\n";
    }
    return 0;
}