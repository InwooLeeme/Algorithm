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

int32_t main(){
	fastio;
	int n,m; cin >> n >> m;
	if(n == 1){
		cout << 0 << '\n';
		return 0;
	}
	vector<int> v(n); for(auto& i : v) cin >> i;
	sort(v.begin(), v.end());
	int ret = 0,l = 0,r = n - 1;
	while(l < r){
		int s = v[l] + v[r];
		if(s >= m) ret++,r--,l++;
		else l++;
	}
	cout << ret << "\n";
	return 0;
}