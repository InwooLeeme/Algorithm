// 1620번 : 나는야 포켓몬 마스터 이다솜

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
    map<int, string> I;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        cin.ignore();
        m.insert({s, i});
        I.insert({i, s});
    }
    for (int i = 0; i < k; i++)
    {
        string v;
        cin >> v;
        if (v[0] >= '0' && v[0] <= '9')
            cout << I[stoi(v)] << "\n";
        else
            cout << m[v] << "\n";
    }
    return 0;
}