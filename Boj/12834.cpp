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

vector<pii> adj[1001];

int dijk(int st, int en)
{
    vi dist(1001, INF);
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    dist[st] = 0;
    PQ.push({0, st});

    while (!PQ.empty())
    {
        auto [weight, cur] = PQ.top();
        PQ.pop();
        if (dist[cur] < weight)
            continue;
        if (cur == en)
            return dist[en];
        for (auto [nWeight, nxt] : adj[cur])
        {
            if (dist[nxt] > nWeight + weight)
            {
                dist[nxt] = nWeight + weight;
                PQ.push({dist[nxt], nxt});
            }
        }
    }
    return -1;
}

int main()
{
    fastio;
    int n, v, e;
    cin >> n >> v >> e; // n : 인원,v : 장소,e :도로
    int a, b;
    cin >> a >> b; // a : kist위치, b : 씨알 위치
    vi member(n);
    for (int i = 0; i < n; i++)
        cin >> member[i];
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }
    // Get dist
    vi ans;
    for (int i = 0; i < n; i++)
    {
        int homeToKist = dijk(member[i], a), homeToC = dijk(member[i], b);
        int total = homeToKist + homeToC;
        ans.pb(total);
    }
    cout << accumulate(all(ans), 0) << "\n";
    return 0;
}