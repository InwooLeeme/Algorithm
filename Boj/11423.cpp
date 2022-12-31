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
}; LinearSieve<100'00'001> Sieve;

int32_t main(){
    fastio;
    int n,m;
    while(cin >> n >> m){
        int cnt = 0;
        for(int i = n; i <= m; i++) if(Sieve.IsPrime(i)) cnt++;
        cout << cnt << "\n\n";
    }
    return 0;
}