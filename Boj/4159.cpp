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
    int n;
    while(cin >> n and n){
        vector<int> v(n);
        for(auto& i : v) cin >> i; sort(v.begin(), v.end());
        cout << [&](){
            if(n == 1) return "IMPOSSIBLE";
            if(v[0] > 200) return "IMPOSSIBLE";
            if(v[n - 1] < 1322) return "IMPOSSIBLE";
            for(int i = 1; i < n; i++) if(v[i] - v[i - 1] > 200) return "IMPOSSIBLE";
            return "POSSIBLE";
        }() << "\n";
    }
    return 0;
}