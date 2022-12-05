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

constexpr int sz = 10'000'000;
int min_fact[sz + 1]; // i의 가장 작은 소인수

void Sieve(){
    for (int i = 0; i <= sz; i++) min_fact[i] = i;
	for (int i = 2; i <= sqrt(sz); i++) {
		if (min_fact[i] != i) continue;
		for (int j = i * i; j <= sz; j += i) {
			min_fact[j] = i;
		}
	}
}

vector<int> SieveWithFactorize(int x){
    vector<int> ret;
    while(min_fact[x] > 1){
        ret.push_back(min_fact[x]);
        x /= min_fact[x];
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int32_t main(){
    fastio;
    int N; cin >> N;
    Sieve();
    for(auto& I : SieveWithFactorize(N)) cout << I << "\n";
    return 0;
}