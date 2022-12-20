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
    map<string, int> M;
    while(cin >> s and s != "000-00-0000"){
        M[s]++;
    }
    vector<string> ret;
    for(auto& [a, b] : M) if(b >= 2) ret.push_back(a);
    sort(ret.begin(), ret.end());
    for(auto& i : ret) cout << i << "\n";
    return 0;
}