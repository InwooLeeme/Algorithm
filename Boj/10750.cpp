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
    string a,b; cin >> a >> b;
    rope<char> rp;
    rp.append(a.c_str());
    const int m = b.size();
    for(int i = 0; i < a.size(); i++){
        if(rp.substr(i, m).c_str() == b){
            rp.erase(i, m);
            i -= m;
        }
    }
    cout << (rp.empty() ? "FRULA" : rp) << "\n";
    return 0;
}