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

int n;
vector<int> g[11111];

struct UnionFind { // union-by-rank ver.
	vector<int> par, rank, cnt;
	UnionFind(int n) : par(n), rank(n, 1), cnt(n, 1) {
		iota(par.begin(), par.end(), 0);
	}
	int Find(int x) {
		return x == par[x] ? x : par[x] = Find(par[x]);
	}
	bool Union(int a, int b) {
		a = Find(a), b = Find(b);
		if (a == b) return 0;
		if (rank[a] < rank[b]) swap(a, b);
		par[b] = a;
		rank[a] += rank[a] == rank[b];
		cnt[a] += cnt[b];
		return 1;
	}
};

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    UnionFind UF(10011);
    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        UF.Union(a, b);
    }
    int a,b;
    while(cin >> a >> b and a and b){
        if(UF.Find(a) == UF.Find(b)){
            cout << "Yes" << " ";
            queue<int> Q;
            Q.push(a);
            vector<int> dist(11111, -1);
            dist[a] = -1;
            while(Q.size()){
                auto cur = Q.front(); Q.pop();
                if(cur == b){
                    cout << dist[cur] << "\n";
                    break;
                }
                for(auto nxt : g[cur]){
                    if(dist[nxt] != -1) continue;
                    dist[nxt] = dist[cur] + 1;
                    Q.push(nxt);
                }
            }
        }
        else cout << "No" << "\n";
    }
    return 0;
}