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
    int a,b,c,d; cin >> a >> b >> c >> d;
    vector<int> v(a),v1(b),v2(c),v3(d);
    for(auto& i : v) cin >> i;
    for(auto& i : v1) cin >> i;
    for(auto& i : v2) cin >> i;
    for(auto& i : v3) cin >> i;
    sort(v3.begin(), v3.end());
    for(auto& i : v){
        for(auto& j : v1){
            for(auto& k : v2){
                if(binary_search(v3.begin(), v3.end(), -(i + j + k))){
                    cout << i << ' ' << j << " " << k << ' ' << -(i + j + k) << "\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}