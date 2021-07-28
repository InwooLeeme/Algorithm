// 1309번 : 동물원

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
#define MAX 1000005
#define INF 1e18
#define mod 9901
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;

ll dp[100001];
int n;

int main()
{
    fastio;
    cin >> n;
    dp[1] = 3;
    dp[2] = 7;
    for (int i = 3; i < 100001; i++)
    {
        dp[i] = (2 * dp[i - 1] + dp[i - 2]) % mod;
    }
    cout << dp[n];
    return 0;
}