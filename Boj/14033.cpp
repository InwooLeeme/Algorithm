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
constexpr int INF = 1LL << 60;
constexpr int NINF = -INF;

int n,m;
vector<pii> g[22];
int D[20][1 << 19];

void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b,c; cin >> a >> b >> c;
        g[a].pb({c, b});
    }
    for(int i = 0; i < (1 << n); i++) for(int j = 0; j < n; j++) D[j][i] = -INF;
    auto sol = [&](int cur, int state, auto&& sol) -> int{
        int& ret = D[cur][state];
        if(ret != -INF) return ret;
        if(cur == n - 1) return ret = 0;
        ret = -INF;
        for(const auto& [cost, nxt] : g[cur]){
            if(state & (1 << nxt)) continue;
            auto sub = sol(nxt, state | (1 << nxt), sol);
            if(sub == -INF) continue;
            ret = max<int>(ret, sub + cost);
        }
        return ret;
    };
    cout << sol(0, 1, sol) << "\n";
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
