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
vector<int> adj[55];
vector<bool> match(55);
vector<int> par(55, -1);

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
}; LinearSieve Sieve;

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> v(n); for(auto& i : v) cin >> i;
    vector<int> ret;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(Sieve.IsPrime(v[i] + v[j])) adj[i].push_back(j), adj[j].push_back(i);
        }
    }
    for(auto& i : adj[0]){
        fill(par.begin(), par.end(), -1);
        par[i] = 0;
        int cnt = 1;
        for(int j = 1; j < n; j++){
            fill(match.begin(), match.end(), 0);
            match[0] = match[i] = 1;
            cnt += DFS(j);
        }
        if(cnt == n - 1) ret.push_back(v[i]);
    }
    if(ret.size() == 0){
        cout << -1 << "\n";
        return 0;
    }
    sort(ret.begin(), ret.end());
    for(auto& i : ret) cout << i << ' ';
    return 0;
}