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

int F(int lo, int hi, int depth, int cur){
    int ret = 0;
    if(depth >= 10) return 0;
    if(cur > hi) return 0;
    if(cur >= lo) ret++;
    ret += F(lo, hi, depth + 1, cur * 10 + 7);
    ret += F(lo, hi, depth + 1, cur * 10 + 4);
    return ret;
}

int32_t main(){
    fastio;
    int a,b; cin >> a >> b;
    cout << F(a, b, 0, 0) << "\n";
    return 0;
}