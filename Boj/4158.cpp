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

int main()
{
    fastio;
    int n, m;
    while (cin >> n >> m && n != 0)
    {
        vi v;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v.pb(a);
        }
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            if (binary_search(all(v), x))
                cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}