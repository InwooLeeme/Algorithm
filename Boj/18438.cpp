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

string a,b,ret;

void LCS(int l1, int r1, int l2, int r2) { // := LCS(a[l1:r1], b[l2:r2])
	// base case
	if (l1 > r1) return;
	if (l1 == r1) {
		for (int i = l2; i <= r2; i++) if (b[i] == a[l1]) {
			ret.push_back(b[i]); break;
		}
		return;
	}

	// DP
	int mid = l1 + r1 >> 1;
	vector<int> LCS1(r2 - l2 + 3), LCS2(r2 - l2 + 3), prv(r2 - l2 + 3);
	for (int i = l1; i <= mid; i++) {
		for (int j = l2; j <= r2; j++) {
			if (a[i] == b[j]) LCS1[j - l2 + 1] = prv[j - l2] + 1;
			else LCS1[j - l2 + 1] = max(LCS1[j - l2], prv[j - l2 + 1]);
		}
		prv = LCS1;
	}
	fill(prv.begin(), prv.end(), 0);
	for (int i = r1; i > mid; i--) {
		for (int j = r2; j >= l2; j--) {
			if (a[i] == b[j]) LCS2[j - l2 + 1] = prv[j - l2 + 2] + 1;
			else LCS2[j - l2 + 1] = max(LCS2[j - l2 + 2], prv[j - l2 + 1]);
		}
		prv = LCS2;
	}

	// DnC
	int mx = -1, idx = 0;
	for (int i = l2; i <= r2 + 1; i++) {
		if (mx < LCS1[i - l2] + LCS2[i - l2 + 1])
			mx = LCS1[i - l2] + LCS2[i - l2 + 1], idx = i;
	}
	LCS(l1, mid, l2, idx - 1);
	LCS(mid + 1, r1, idx, r2);
}
int32_t main(){
    fastio;
    cin >> a >> b;
    LCS(0, a.size() - 1, 0, b.size() - 1);
    cout << ret.size() << "\n" << ret << "\n";    
    return 0;
}