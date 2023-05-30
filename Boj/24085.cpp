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
    int n; cin >> n;
    map<int, int> M;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        M[t]++;
        v.push_back(t);
    }
    v.erase(unique(v.begin(), v.end()), v.end());
    sort(v.begin(), v.end(), [&](int& a, int& b){ return M[a] == M[b] ? a < b : M[a] < M[b]; });
    cout << v[0] << "\n";
    return 0;
}