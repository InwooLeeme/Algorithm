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
    int n,m,k; cin >> n >> k >> m;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        if(t > k and t < 2*k) v.push_back(t - k);
        else if(t > 2*k) v.push_back(t - 2*k);
    }
    sort(v.begin(), v.end());
    auto Check = [&](const int mid) -> bool{
        int cnt = 0;
        for(auto& i : v) cnt += (i / mid);
        return cnt >= m;
    };
    int lo = 0, hi = 1e18;
    while(lo + 1 < hi){
        int mid = lo + hi >> 1;
        if(Check(mid)) lo = mid;
        else hi = mid;
    }
    if(!lo) cout << -1 << '\n';
    else cout << lo << "\n";
    return 0;
}