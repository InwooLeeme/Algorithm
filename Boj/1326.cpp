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

int32_t main()
{
    fastio;
    int n, a, b;
    cin >> n;
    vector<int> v(n), dist(n, -1);
    for (auto &i : v)
        cin >> i;
    cin >> a >> b;
    --a, --b;
    queue<int> Q;
    Q.push(a), dist[a] = 0;
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int i = 1; cur - v[cur] * i >= 0 || cur + v[cur] * i < n; i++)
        {
            for (auto nxt : {cur - v[cur] * i, cur + v[cur] * i})
            {
                if (0 <= nxt && nxt < n && dist[nxt] == -1)
                {
                    Q.push(nxt);
                    dist[nxt] = dist[cur] + 1;
                }
            }
        }
    }
    cout << dist[b] << "\n";
}