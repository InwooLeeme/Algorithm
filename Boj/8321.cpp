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
    int n,m,k; cin >> n >> m >> k;
    vector<int> v(n);
    for(auto& i : v) cin >> i;
    sort(v.rbegin(), v.rend());
    int cnt = 0,lt = k * m;
    for(auto& i : v){
        if(lt <= 0) break;
        lt -= i;
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}