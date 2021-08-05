// 1764번 : 듣보잡

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <tuple>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <complex>
#include <cassert>
#define X first
#define Y second
#define pb push_back
#define MAX 500001
#define INF 1000000000
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    vector<string> ans;
    vector<string> nosee(n), noHear(m);
    for (int i = 0; i < n; i++)
        cin >> nosee[i];
    for (int j = 0; j < m; j++)
        cin >> noHear[j];
    sort(nosee.begin(), nosee.end());
    sort(noHear.begin(), noHear.end());
    for (int j = 0; j < noHear.size(); j++)
    {
        if (binary_search(nosee.begin(), nosee.end(), noHear[j]))
        {
            ans.pb(noHear[j]);
        }
    }
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}