#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fi first
#define se second
#define pb push_back
#define si(x) (int)x.size()

using pii = pair<int, int>;
using ti3 = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int PRECISION = 0;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
constexpr int INF = int(2e18);
constexpr int NINF = -INF;



void solve(){
    int n; cin >> n;
    vector<string> s(n); for(auto& i : s) cin >> i;
    vector<vector<int>> D(n + 1, vector<int>((1 << n) + 1, -1));
    auto sol = [&](int cur, int state, auto&& sol) -> int{
        if(state == (1 << n) - 1) return 0;
        int& ret = D[cur][state];
        if(ret != -1) return ret;
        ret = 0;
        for(int i = 0; i < n; i++){
            if(state & (1 << i)) continue;
            if(s[cur].back() != s[i][0]) continue;
            ret = max<int>(ret, sol(i, state | (1 << i), sol) + s[i].size());
        }
        return ret;
    };
    int mx = 0;
    for(int i = 0; i < n; i++) mx = max<int>(mx, sol(i, 1 << i, sol) + s[i].size());
    cout << mx << "\n";
}

void Main(){
    int t = 1; 
    //cin >> t;
    while(t--) solve();
    /* for(int tc = 1; tc <= t; tc++){
    cout << "Case #" << tc << ": "; solve();
    } */
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
