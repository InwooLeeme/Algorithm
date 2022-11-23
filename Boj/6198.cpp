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
    int n,ret = 0; cin >> n;
    vector<int> v(n);
    stack<int> S;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++){
        while(S.size() and S.top() <= v[i]) S.pop();
        ret += (int)S.size();
        S.push(v[i]);
    }
    cout << ret;
    return 0;
}