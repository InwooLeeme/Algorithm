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
    int n,q; cin >> n >> q;
    vector<int> v(n);
    for(auto& i : v) cin >> i;
    int s = 0;    
    while(q--){
        int t,a,b; cin >> t >> a; 
        if(t == 1){
            cin >> b;  --a;
            v[(s + a) % n] += b;
        }
        else if(t == 2) s = (s - a + n) % n;
        else if(t == 3) s = (s + a) % n;
    }
    for(int i = 0; i < n; i++) cout << v[(i + s) % n] << ' ';
    return 0;
}