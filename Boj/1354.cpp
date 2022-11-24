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

int n,p,q,x,y;
map<int, int> M;

int F(int cur){
    if(M.count(cur)) return M[cur];
    return M[cur] = F((floor(cur / p) - x < 0 ? 0 : floor(cur / p) - x)) + F((floor(cur / q) - y < 0 ? 0 : floor(cur / q) - y));
}

int32_t main(){
    fastio;
    cin >> n >> p >> q >> x >> y;
    M[0] = 1;
    cout << F(n) << "\n";
    return 0;
}