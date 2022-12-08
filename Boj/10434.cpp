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

bool IsPrime(int x){
    if(x <= 1) return 0;
    for(int i = 2; i * i <= x; i++) if(x % i == 0) return 0;
    return 1;
}

int Check(int x){
    int ret = 0;
    string s = to_string(x);
    for(auto &p : s) ret += (p - '0') * (p - '0');
    return ret;
}

string Sol(int x){
    if(!IsPrime(x)) return "NO";
    set<int> S;
    while(1){
        S.insert(x);
        x = Check(x);
        if(x == 1) break;
        if(S.count(x)) return "NO";
    }
    return "YES";
}

int32_t main(){
    fastio;
    int T; cin >> T;
    while(T--){
        int k,n; cin >> k >> n;
        cout << k << ' ' << n << ' ' << Sol(n) << "\n";
    }
    return 0;
}