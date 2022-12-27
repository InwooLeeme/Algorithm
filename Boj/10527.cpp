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

#define int int_fast64_t

int32_t main(){
    fastio;
    int N; cin >> N; cin.ignore();
    map<string, int> a,b;
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        a[s]++;
    }
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        b[s]++;
    }
    int ret = 0;
    for(auto& [x, y] : a){
        ret += min<int>(y, b[x]);
    }
    cout << ret << "\n";
    return 0;
}