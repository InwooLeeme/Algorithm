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

using pii = pair<int,int>;

template<size_t sz>
struct Fenwick{
    int tree[sz + 1];
    void Update(int i, int x){
        for(; i <= sz; i += i & -i) tree[i] += x;
    }
    int Query(int i){
        int ret = 0;
        for(; i; i -= i & -i) ret += tree[i];
        return ret;
    }
};

int n,m;
Fenwick<1 << 19> FT;
vector<int> adj[1 << 19];
pii Ett[1 << 19];

void DFS(int cur = 1){
    static int temp = 0;
    Ett[cur].first = ++temp;
    for(auto nxt : adj[cur]) DFS(nxt);
    Ett[cur].second = temp;
}

int32_t main(){
    fastio;
    cin >> n >> m;
    for(int i = 1,t; i <= n; i++){
        cin >> t;
        if(i == 1) continue;
        adj[t].push_back(i);
    }
    DFS();
    while(m--){
        int t,x,y; cin >> t;
        if(t == 1){
            cin >> x >> y;
            FT.Update(Ett[x].first, y);
            FT.Update(Ett[x].second + 1, -y);
        }
        else{
            cin >> x;
            cout << FT.Query(Ett[x].first) << "\n";
        } 
    }
    return 0;
}