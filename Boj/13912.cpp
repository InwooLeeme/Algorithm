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

const int MOD = 1e9 + 7;
int f[2222];
int d[111];

// mod inverse
int minv(int x,int y){
	int p = MOD - 2;
	for(; p; p >>= 1){
		if(p & 1) x = x * y % MOD;
		y = y * y % MOD;
	}
	return x;
}

int GetCombi(int n, int k) { return minv(f[n] , f[k] * f[n - k] % MOD); }

int32_t main(){
    fastio;
    int n; cin >> n;
    f[0] = 1;
    for(int i = 1; i <= 2222; i++) f[i] = f[i - 1] * i % MOD;
    d[0] = 1,d[1] = 2;
    for(int i = 2; i <= n; i++) d[i] = ((d[i - 1] * d[i - 1] % MOD) * GetCombi((1 << (i + 1)) - 2, (1 << i) - 1)) % MOD;
    cout << d[n] << "\n";
    return 0;
}