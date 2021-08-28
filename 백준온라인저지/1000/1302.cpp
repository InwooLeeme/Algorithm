// 1302번 : 베스트셀러

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
    map<string, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (m.find(s) != m.end())
            m[s]++;
        else
            m[s] = 1;
    }
    auto ans = *max_element(m.begin(), m.end(), [](const pair<string, int> &a, const pair<string, int> &b)
                            { return a.second < b.second; });
    cout << ans.first << "\n";
    return 0;
}