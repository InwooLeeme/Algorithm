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
    vector<int> v(n);
    for(auto& i : v) cin >> i;
    auto Check = [&](const int mid) -> bool{
        int cnt = 0,s = 0;
        for(auto& i : v){
            if(s + i > mid) cnt++,s = 0;
            if(s + i > mid) return 0;
            s += i;
        }
        return cnt < m;
    };
    int lo = -1, hi = int(1e18);
    while(lo + 1 < hi){
        int mid = lo + hi >> 1;
        if(!Check(mid)) lo = mid;
        else hi = mid;
    }
    cout << hi << "\n";
    return 0;
}