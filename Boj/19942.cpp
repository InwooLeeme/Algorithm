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

const int INF = int(2e9);

struct P{
    int p,f,s,v,c;
};

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,mn = INF,mp,mf,ms,mv; cin >> n >> mp >> mf >> ms >> mv;
    map<int, vector<vector<int>>> M;
    vector<P> info(n);
    for(auto& [p, f, s, v, c] : info) cin >> p >> f >> s >> v >> c;
    for(int i = 1; i < (1 << n); i++){
        int cntp = 0,cntf = 0,cnts = 0,cntv = 0,cost = 0;
        vector<int> v;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                cntp += info[j].p;
                cntf += info[j].f;
                cnts += info[j].s;
                cntv += info[j].v;
                cost += info[j].c;
                v.push_back(j + 1);
            }
            if(mn >= cost and cntp >= mp and cntf >= mf and cnts >= ms and cntv >= mv){
                mn = cost;
                M[mn].push_back(v);
            }
        }
    }
    cout << (mn == INF ? -1 : mn) << "\n";
    if(mn != INF){
        sort(M[mn].begin(), M[mn].end());
        for(auto& c : M[mn][0]) cout << c << " ";
    }
    return 0;
}