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

const int PRECISION = 0;

void Sol(int x){
    int n,ret = 0; set<int> S = {x}; vector<int> v = {x}; while(1){
        int x; cin >> x;
        if(!x) break;
        v.push_back(x);
        S.insert(x);
    }
    for(auto& i : v){
        if(S.count(i << 1)) ret++;
    }
    cout << ret << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    int t; while(cin >> t and t != -1) Sol(t);
    return 0;
}