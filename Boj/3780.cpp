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

struct UnionFind{
    vector<int> par,dist;
    UnionFind(int n = 0):par(n),dist(n){
        iota(par.begin(), par.end(), 0);
    }
    int Find(int x){
        if(x == par[x]) return x;
        if(par[x] != par[par[x]]){
            int p = par[x]; par[x] = Find(par[x]);
            dist[x] += dist[p];
        }
        return par[x];
    }
    void Union(int a,int b){
        par[a] = b;
        dist[a] = abs(a - b) % 1000;
    }
};

void test_case(){
    int n; cin >> n;
    UnionFind UF(n + 1);
    char c;
    while(cin >> c and c != 'O'){
        int a,b;
        if(c == 'I') cin >> a >> b,UF.Union(a, b);
        else cin >> a,UF.Find(a), cout << UF.dist[a] << "\n";
    }
}

int32_t main(){
    fastio;
    int T; cin >> T;
    while(T--) test_case();
    return 0;
}