// 1269번 : 대칭 차집합

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

int main()
{
    fastio;
    set<int> a, b;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        a.insert(t);
    }
    for (int i = 0; i < k; i++)
    {
        int c;
        cin >> c;
        b.insert(c);
    }
    int ans = 0;
    for (auto i = a.begin(); i != a.end(); i++)
    {
        if (b.find(*i) == b.end())
            ans++;
    }
    for (auto i = b.begin(); i != b.end(); i++)
    {
        if (a.find(*i) == a.end())
            ans++;
    }
    cout << ans << "\n";
    return 0;
}