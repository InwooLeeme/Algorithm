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
using tii = tuple<int, int, int>;
template <typename T>
using wector = vector<vector<T>>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll LNF = 1e18 + 7;

int dist[101];
vector<pii> adj[101];

priority_queue<pii, vector<pii>, greater<pii>> PQ;

int main()
{
    fastio;
    int n, k;
    cin >> n >> k;
    while (k--)
    {
        int q, a, b, c, d, e;
        cin >> q;
        if (q == 1)
        { // 갱신
            cin >> c >> d >> e;
            adj[c].pb({e, d});
            adj[d].pb({e, c});
        }
        else
        { // Query
            cin >> a >> b;
            fill(dist, dist + 101, INF);
            dist[a] = 0;
            PQ.push({0, a});
            while (!PQ.empty())
            {
                auto [weight, cur] = PQ.top();
                PQ.pop();
                if (dist[cur] < weight)
                    continue;
                for (auto [nWeight, nx] : adj[cur])
                {
                    if (dist[nx] > nWeight + weight)
                    {
                        dist[nx] = nWeight + weight;
                        PQ.push({dist[nx], nx});
                    }
                }
            }
            cout << (dist[b] == INF ? -1 : dist[b]) << "\n";
        }
    }
    return 0;
}