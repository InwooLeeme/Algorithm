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

int32_t main(){
    fastio;
    int T,P,a,b; cin >> P >> T;
    vector<vector<int>> A(P + 1);
	while (cin >> a >> b) {
		A[a].push_back(b);
	}
	for(auto &v : A) {
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
	}
	int ret = 0;
	for (int i = 1; i <= P; ++i) {
		if (A[i].size() == 1 && A[i][0] == -1) {
			continue;
		}
		for (int j = i + 1; j <= P; ++j) {
			if (A[i] == A[j]) {
				A[j] = {-1};
			}
		}
		++ret;
	}
	cout << ret << "\n";
    return 0;
}