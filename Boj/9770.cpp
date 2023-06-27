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
    vector<int> v;
    int ret = 0,x;
    while(cin >> x) v.push_back(x);
    for(int i = 0; i < v.size(); i++){
        for(int j = i + 1; j < v.size(); j++) ret = max<int>(ret, __gcd(v[i], v[j]));
    }
    cout << ret << "\n";
    return 0;
}