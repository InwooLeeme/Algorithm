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

struct Info{
    bool flag;
    int cnt;
    Info():flag(0),cnt(0){}
};

int32_t main(){
    fastio;
    int n; cin >> n;
    map<string, Info> M;
    for(int i = 0; i < n; i++){
        int a,b,c,d,e,f; string s; cin >> a >> s >> b >> c >> d >> e >> f;
        if(M[s].flag) continue;
        if(b == 4) M[s].flag = 1; // 정답
        else M[s].cnt++;
    }   
    int t1 = 0,t2 = 0;
    for(const auto& [a, i] : M){
        if(!i.flag || a == "megalusion") continue;
        t1++,t2 += i.cnt;
    }
    if(!t1) cout << 0 << "\n";
    else cout << fixed << setprecision(20) <<  100. * t1 / (t1 + t2) << "\n";
    return 0;
}