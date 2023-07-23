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
    int n,m,k,ret = 0; cin >> n >> m >> k;
    vector<int> v(n * m);
    for(int i = 0; i < n*m; i++) cin >> v[i];
    for(int i = 0; i < v.size(); i += m){
        int cnt = 0;
        for(int j = i; j < i + m; j++) cnt += !v[j];
        if(cnt < k) ret++;
    }
    cout << ret << '\n';
    return 0;
}