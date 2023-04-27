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
    int a,b; cin >> a >> b;
    int g = __gcd(a, b);
    vector<int> v;
    for(int i = 1; i * i <= g; i++){
        if(g % i == 0) v.push_back(i),v.push_back(g / i);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(auto& i : v){
        cout << i << " " << (a / i) << " " << (b / i) << "\n";
    }
    return 0;
}