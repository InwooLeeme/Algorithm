#pragma GCC target("avx,avx2,fma")
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

const int PRECISION = 0;

constexpr int INF = int(2e18);

vector<int> d(111'111);

void Main(){
	int n,m; cin >> m >> n;
	vector<int> w(n + 1), v(n + 1);
	for(int i = 0; i < n; i++) cin >> w[i] >> v[i];
	d[0] = INF;
	for(int i = 0; i < n; i++){
		for(int j = m; j >= w[i]; j--) d[j] = max<int>(d[j], min<int>(d[j - w[i]], v[i]));
	}
	cout << d[m] << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
	return 0;
}
