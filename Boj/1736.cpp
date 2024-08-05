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

void Main(){
    using p = pair<int, int>;
    int n,m; cin >> n >> m;
    int v[111][111]{};
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> v[i][j];
    vector<p> w;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(v[i][j]) w.push_back({i, j});
    sort(w.begin(), w.end(), [&](p& a, p& b){
        return a.first == b.first ? a.second > b.second : a.first > b.first;
    });
    vector<int> LIS;
    for(const auto& [a, b] : w){
        if(LIS.empty() or LIS.back() < b) LIS.push_back(b);
        else *lower_bound(LIS.begin(), LIS.end(), b) = b;
    }
    cout << LIS.size() << "\n";
}   

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
