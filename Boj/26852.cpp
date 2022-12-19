#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int64_t

int N, M;
vector<vector<int>> dp;
void solve() {
    cin >> N >> M;
    vector<pair<int, int>> v(N+1); // <weight, value>
    for(int i=1; i<=N; i++) cin >> v[i].second >> v[i].first;
    dp.resize(N+1, vector<int>(M+1));
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++) {
            dp[i][j] = dp[i-1][j];
            if(v[i].first <= j)
                dp[i][j] = max(dp[i][j], dp[i-1][j - v[i].first] + v[i].second);
        }
    cout << dp[N][M] << "\n";
}

int32_t main(){
    fastio;
    int T; cin >> T;
    while(T--) solve();
    return 0;
}