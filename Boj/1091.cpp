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

using vi = vector<int>;

struct Game{
    int n;
    vi p,s,ans;
    set<vi> S;
    Game(int n):n(n),p(n),s(n),ans(n){
        Init();
    }

    void Init(){
        for(auto& i : p) cin >> i;
        for(auto& i : s) cin >> i;
        for(int i = 0; i < n; i++) ans[i] = (i % 3);
    }

    vi ShuFFle(vi& v){
        vi ret(n);
        for(int i = 0; i < n; i++){
            auto t = v[i];
            ret[s[i]] = t;
        }
        return ret;
    }
    
    int Sol(){
        int ret = 0;
        while(p != ans){
            auto v = ShuFFle(p);
            p = v;
            if(S.count(p)) return -1;
            S.insert(v);
            ret++;
        }
        return ret;
    }
};

int32_t main(){
    fastio;
    int n; cin >> n;
    Game G(n);
    cout << G.Sol() << "\n";
    return 0;
}