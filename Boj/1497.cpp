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

int n,m,ret,sret,g[22];

int cnt(int x){
    bitset<55> b(x);
    return b.count();
}

void F(int depth, int gg, int ss){
    int scnt = cnt(ss);
    if(sret < scnt){
        sret = scnt;
        ret = gg;
    }
    else if(sret == scnt) ret = min<int>(ret, gg);
    if(depth >= n) return;
    F(depth + 1, gg, ss);
    F(depth + 1, gg + 1, ss | g[depth]);
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    bool flag = 1;
    for(int i = 0; i < n; i++){
        string a,s; cin >> a >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == 'N') continue;
            g[i] |= (1LL << j);
            flag = 0;
        }
    }
    if(flag){
        cout << -1 << "\n";
        return 0;
    }
    F(0, 0, 0);
    cout << ret << "\n";
    return 0;
}