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
    int n,m;
    while(cin >> n >> m and n){
        vector<int> a(n),b(m);
        for(auto& i : a) cin >> i;
        for(auto& i : b) cin >> i;
        vector<int> ret(10);
        for(auto& i : a) for(auto& j : b){
            int s = i * j;
            while(s){
                ret[s % 10]++;
                s /= 10;
            }
        }
        for(auto& i : ret) cout << i << " ";
        cout << '\n';
    }
    return 0;
}