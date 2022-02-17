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

int dp[26][200001];

int32_t main()
{
    fastio;
    int q;
    string s;
    cin >> s >> q;
    for (int i = 0; i < s.size(); i++)
    {
        dp[s[i] - 'a'][i + 1]++;
    }
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            dp[j][i] = dp[j][i] + dp[j][i - 1];
        }
    }
    while (q--)
    {
        int s, e;
        char c;
        cin >> c >> s >> e;
        cout << dp[c - 'a'][e + 1] - dp[c - 'a'][s] << "\n";
    }
}