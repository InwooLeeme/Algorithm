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

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,m; cin >> n >> m;
    map<int, int> M;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){
            int t; cin >> t;
            M[j] += t;
        }
    }
    vector<int> v(m);
    iota(v.begin(), v.end(), 1);
    sort(v.begin(), v.end(), [&](int& a, int& b){
        return M[a] == M[b] ? a < b : M[a] > M[b];
    });
    for(const auto& i : v) cout << i << " ";
    return 0;
}