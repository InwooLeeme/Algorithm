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

const int PRECISION = 0;

void Sol(){
    int n,m,s1,s2; cin >> n >> m;
    const int INF = int(2e18);
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    while(m--) { int a,b,c; cin >> a >> b >> c; dist[a][b] = min<int>(dist[a][b], c); dist[b][a] = min<int>(dist[b][a], c); }
    cin >> s1 >> s2;
    for(int i = 1; i <= n; i++) dist[i][i] = 0;
    // floyd
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dist[i][j] = min<int>(dist[i][j], dist[i][k] + dist[k][j]);
    vector<int> ret;
    int center = INF;
    for(int i = 1; i <= n; i++) if(i != s1 and i != s2) center = min<int>(center, dist[s1][i] + dist[s2][i]);
    for(int i = 1; i <= n; i++) if(i != s1 and i != s2 and dist[s1][i] <= dist[s2][i] and dist[s1][i] + dist[s2][i] <= center) ret.push_back(i);
    sort(ret.begin(), ret.end(), [&](int& a, int& b){ return dist[s1][a] < dist[s1][b]; });
    cout << (!ret.size() ? -1 : ret[0]) << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Sol();
    return 0;
}