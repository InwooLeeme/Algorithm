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

void Sol(){
	int n,mx = int(-2e9); cin >> n;
	vector<vector<int>> p(n + 1, vector<int>(n + 1));
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
		int t; cin >> t;
		p[i + 1][j + 1] = p[i + 1][j] + p[i][j + 1] - p[i][j] + t;
	}
	auto Query = [&](int r1, int c1, int r2, int c2) -> int{ return p[r2][c2] - p[r1][c2] - p[r2][c1] + p[r1][c1]; };
	for(int k = 1; k <= n; k++){
		for(int r2 = k; r2 <= n; r2++) for(int c2 = k; c2 <= n; c2++){
			mx = max<int>(mx, Query(r2 - k, c2 - k, r2, c2));
		}
	}
	cout << mx << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Sol();
    return 0;
}
