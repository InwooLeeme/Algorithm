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
    int n,m; cin >> n >> m;
    vector<string> a(n),b(n),s(n); for(auto& i : a) cin >> i; for(auto& i : b) cin >> i;
    for(int i = 0; i < n; i++){
        for(int k = 0; k < m; k++){
            for(int j = 0; j < 2; j++) s[i].push_back(a[i][k]);
        }
    }
    cout << (b == s ? "Eyfa" : "Not Eyfa") << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}