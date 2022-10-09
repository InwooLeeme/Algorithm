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

int32_t main(){
    fastio;
    int n,m; cin >> n;
    vector<bool> a(n + 1, 0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[x] = 1;
    }
    cin >> m;
    int ret = 0;
    for(int i = 0; i < m; i++){
        int k; cin >> k;
        bool flag = 0;
        while(k--){
            int x; cin >> x;
            if(a[x]) {flag = 1;}
        }
        if(flag) continue;
        ret++;
    }
    cout << ret << "\n";
    return 0;
}