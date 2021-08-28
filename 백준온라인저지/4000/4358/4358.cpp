// 4358번 : 생태학

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
    map<string, float> m;
    float cnt = 0;
    string s;
    while (getline(cin, s))
    {
        cnt++;
        m[s]++;
    }
    for (auto i = m.begin(); i != m.end(); i++)
    {
        float k = (i->second / cnt) * 100; // 백분율
        cout << fixed << setprecision(4) << i->first << ' ' << k << "\n";
    }
    return 0;
}