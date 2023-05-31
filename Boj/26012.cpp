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

template<size_t sz = 100'000>
struct LinearSieve {
	vector<int> p;
	int sieve[sz + 1]; // sieve[i] : IsPrime(i) ? 0 : smallest prime factor
	LinearSieve() : sieve{} {
		sieve[0] = sieve[1] = -1;
		for (int i = 2; i <= sz; i++) {
			if (!sieve[i]) p.push_back(i);
			for (auto j : p) {
				if (i * j > sz) break;
				sieve[i * j] = j;
				if (i % j == 0) break;
			}
		}
	}
	bool IsPrime(int n) { return !sieve[n]; }
}; LinearSieve<20000000> Sieve;

// 1 - indexed base // 
struct BM{
	int n;
	vector<vector<int>> adj;
	vector<int> par;
	vector<bool> match;
	
	BM(int n = 0): n(n),adj(n + 1),par(n + 1, -1),match(n + 1, 0){}
	void AddEdge(int a,int b){ adj[a].push_back(b);}
	
	int DFS(int cur){
		for(auto nxt : adj[cur]){
			if(match[nxt]) continue;
			match[nxt] = 1;
			if(par[nxt] == -1 or DFS(par[nxt])){
				par[nxt] = cur;
				return 1;
			}
		}
		return 0;
	}
	
	int Matching(){
		int ret = 0;
		for(int i = 0; i < n; i++){
			fill(match.begin(), match.end(), 0);
			ret += DFS(i);
		}
		return ret;
	}
};

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<int> v,w;
    bool check = 0;
    for(int i = 1; i <= n; i++){
        int t; cin >> t;
        if(t == 1){
            if(check) continue;
            check = 1;
            v.push_back(t);
            continue;
        }
        if(t & 1) v.push_back(t);
        else w.push_back(t);
    }
    BM G(755);
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < w.size(); j++){
            if(Sieve.IsPrime(v[i] + w[j])) G.AddEdge(i, j);
        }
    }
    cout << v.size() + w.size() - G.Matching() << "\n";
    return 0;
}