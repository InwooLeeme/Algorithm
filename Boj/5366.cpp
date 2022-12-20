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

int32_t main(){
    fastio;
    string s; 
    vector<pair<int,string>> v;
    map<string,int> M;
    int idx = 1;
    while(1){
        getline(cin, s); 
        if(s == "0") break;
        if(!M.count(s)) v.push_back({idx, s});
        M[s]++;
        idx++;
    }
    sort(v.begin(), v.end());
    int ret = 0;
    for(auto& [val, name] : v){
        cout << name << ": " << M[name] << "\n";
        ret += M[name];
    }
    cout << "Grand Total: " << ret << "\n";
    return 0;
}